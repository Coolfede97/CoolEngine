#include "GameObject.h"
#include "Game.h"

void GameObject::Start()
{
	// Do stuff
}
GameObject::GameObject(Transform transform_in, string name_in, bool active_in)
{
	transform = transform_in;
	name = name_in;
	Game::gameObjects.push_back(*this);
	if (active_in) Start();
}

