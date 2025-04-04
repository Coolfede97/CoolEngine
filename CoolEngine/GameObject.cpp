#include <iostream>
#include <string>
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
#include "Component.h"
#include <atomic>
using namespace std;


atomic<int> GameObject::lastID(0);

// Is called the first frame where this GameObject is activated (not in the same when created)
void GameObject::Start()
{
	// Do Stuff
	startCalled = true;
	for (const auto& component : components)
	{
		component.second->Start();
	}
}

// Called every frame. It calls every component's Update, and Start if it's first time
void GameObject::Update()
{
	// Do Stuff
	if (!active) return;
	if (!startCalled) Start();
	for (const auto& component : components)
	{
		component.second->Update();
	}
}
// Called every frame. It calls every component's Draw
void GameObject::Draw()
{
	if (!active) return;
	for (const auto& component : components)
	{
		component.second->Draw();
	}
}
GameObject* GameObject::Instantiate()
{
	return new GameObject();
}
void GameObject::Destroy()
{
	vector<GameObject*>* gos = &Game::gameObjects;
	vector<GameObject*>* gosToAdd = &Game::gameObjectsToAdd;
	for (int i = 0; i < gos->size(); i++)
	{
		if ((*gos)[i]->ID == this->ID) gos->erase(gos->begin() + i);
	}
	for (int i = 0; i < gosToAdd->size(); i++)
	{
		if ((*gosToAdd)[i]->ID == this->ID) gosToAdd->erase(gosToAdd->begin() + i);
	}
	delete this;
}

GameObject GameObject::operator=(const GameObject& other)
{
	transform = other.transform;
	name = other.name;
	return *this;
}

GameObject::GameObject(string name_in, GameObjectsTags gameObjectTag_in, bool active_in)
{
	transform = new Transform();
	name = name_in;
	active = active_in;
	startCalled = false;
	tag = gameObjectTag_in;
	lastID++;
	ID = lastID;
	Game::gameObjectsToAdd.push_back(this);
}



