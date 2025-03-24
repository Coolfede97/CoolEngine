#include <iostream>
#include <string>
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
#include "Component.h"
using namespace std;
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
GameObject GameObject::operator=(const GameObject& other)
{
	transform = other.transform;
	name = other.name;
	return *this;
}
GameObject::GameObject(string name_in, bool active_in)
{
	transform = new Transform(this);
	name = name_in;
	Game::gameObjects.push_back(this);
	if (active_in) Start();
}

