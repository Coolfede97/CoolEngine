#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <typeindex>
#include "CoolComponents.h"
#include <unordered_map>
#include <vector>
#include <atomic>
#include "Game.h"


class GameObject
{
public:
	GameObject(string name_in="newGameObject", GameObjectsTags gameObjectTag_in = GameObjectsTags::Untagged, bool active_in = true);
	
	Transform* transform;
	
	GameObjectsTags tag;
	string name;
	int renderingIndex;
	bool active;
	GameObject* father;
	vector<GameObject*> children;

	bool startCalled;
	static atomic<int> lastID;
	int ID;
	unordered_map<type_index, Component*> components;
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	static GameObject* Instantiate();
	bool RemoveIn(vector<GameObject*>& vector);
	void Destroy();

	void MakeFatherOf(GameObject*& child_in);
	void MakeChildOf(GameObject*& father_in);

	virtual ~GameObject() = default;
	GameObject operator=(const GameObject& other);




	template<typename T>
	T* AddComponent();

	template<typename T>
	T* GetComponent();


};

template<typename T>
inline T* GameObject::AddComponent()
{
	components[typeid(T)] = new T();
	components[typeid(T)]->owner = this;
	return dynamic_cast<T*>(components[typeid(T)]);
}

template<typename T>
inline T* GameObject::GetComponent()
{
	for (const auto& component : components)
	{
		if (dynamic_cast<T*>(component.second))
		{
			return dynamic_cast<T*>(component.second);
		}
	}
}


