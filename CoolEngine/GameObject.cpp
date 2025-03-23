#include <iostream>
#include <string>
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
using namespace std;
void GameObject::Start()
{
	// Do stuff
}
void GameObject::Update()
{
	// Do Stuff
}
void GameObject::Draw()
{
	// Draw stuff
}
GameObject::GameObject(Transform transform_in, string name_in, bool active_in)
{
	transform = transform_in; 
	name = name_in;
	Game::gameObjects.push_back(*this);
	if (active_in) Start();
}

