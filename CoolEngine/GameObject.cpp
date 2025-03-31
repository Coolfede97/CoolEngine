#include <iostream>
#include <string>
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
#include "Component.h"
#include <atomic>
using namespace std;


atomic<int> GameObject::lastID(0);

void GameObject::Start()
{
	// Do Stuff
	startCalled = true;
	for (const auto& component : components)
	{
		component.second->Start();
	}
}
void GameObject::Update()
{
	// Do Stuff
	if (!startCalled && active) Start();
	for (const auto& component : components)
	{
		component.second->Update();
	}
}
void GameObject::Draw()
{
	// Draw stuff
}
GameObject* GameObject::Instantiate()
{
	return new GameObject();
}
GameObject GameObject::operator=(const GameObject& other)
{
	transform = other.transform;
	name = other.name;
	return *this;
}
GameObject::GameObject(string name_in, GameObjectsTags gameObjectTag_in, bool active_in)
{
	transform = new Transform(this);
	name = name_in;
	active = active_in;
	startCalled = false;
	gameObjectTag = gameObjectTag_in;
	lastID++;
	ID = lastID;
	Game::gameObjectsToAdd.push_back(this);
}



