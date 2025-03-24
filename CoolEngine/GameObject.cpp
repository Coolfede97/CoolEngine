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
	for (Component* component : components)
	{
		component->Start();
	}
}
void GameObject::Update()
{
	// Do Stuff
	for (Component* component : components)
	{
		component->Update();
	}
}
void GameObject::Draw()
{
	// Draw stuff
}
GameObject GameObject::operator=(GameObject other)
{
	transform = other.transform;
	name = other.name;
	return *this;
}
GameObject::GameObject(Transform transform_in, string name_in, bool active_in)
{
	transform = transform_in; 
	name = name_in;
	Game::gameObjects.push_back(this);
	if (active_in) Start();
}

