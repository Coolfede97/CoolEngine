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
	// Do stuff
	for (const auto& component : components)
	{
		component.second->Start();
	}
}
void GameObject::Update()
{
	// Do Stuff
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
GameObject::GameObject(string name_in, SceneGameObjects gameObjectType_in, bool active_in)
{
	transform = new Transform(this);
	name = name_in;
	active = active_in;
	gameObjectType = gameObjectType_in;
	lastID++;
	ID = lastID;
	cout << name << endl;
	cout << ID << endl;
	Game::gameObjects.push_back(this);
	if (active_in) Start();
}



