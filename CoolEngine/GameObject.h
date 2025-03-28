#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Transform.h"
#include "Component.h"
#include <unordered_map>
#include <vector>
#include <atomic>
#include "Game.h"
class GameObject
{
public:
	GameObject(string name_in="newGameObject", SceneGameObjects gameObjectType_in = SceneGameObjects::Untagged, bool active_in = true);
	Transform* transform;
	SceneGameObjects gameObjectType;
	string name;
	bool active;
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
	T* GetComponent(ComponentOfType targetType);

};

template<typename T>
inline T* GameObject::GetComponent(ComponentOfType targetType)
{
	for (const auto& component : components)
	{
		if (component.second->type == targetType)
		{
			return dynamic_cast<T*>(component.second);
		}
	}
}
