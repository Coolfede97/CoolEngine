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
	bool active;
	bool startCalled;
	static atomic<int> lastID;
	int ID;
	unordered_map<type_index, Component*> components;
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	static GameObject* Instantiate();
	void Destroy();

	virtual ~GameObject() = default;
	GameObject operator=(const GameObject& other);

	template<typename T>
	void AddComponent();

	template<typename T>
	T* GetComponent();


};

template<typename T>
inline void GameObject::AddComponent()
{
	// TIENE BUENA PINTA, PERO FALTA ALGUNA MANERA DE ASIGNAR EL OWNER AL COMPONENT.
	// PLAN: CAMBIAR EL CONSTRUCTOR PARA AGREGARLE EL OWNER CON "THIS" EN ESTA FUNCION
	//newComponent.owner
	components[typeid(T)] = new T();
	components[typeid(T)]->owner = this;
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


