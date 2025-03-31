#pragma once
using namespace std;
#include <iostream>
#include <string>
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
	GameObjectsTags gameObjectTag;
	string name;
	bool active;
	bool startCalled;
	static atomic<int> lastID;
	int ID;
	unordered_map<ComponentOfType, Component*> components;
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	static GameObject* Instantiate();
	
	virtual ~GameObject() = default;
	GameObject operator=(const GameObject& other);

	template<typename T>
	T* GetComponent();

};

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
