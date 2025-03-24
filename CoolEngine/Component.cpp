#include "Component.h"
#include "GameObject.h"
Component::Component(GameObject* owner_in, string name_in)
{
	owner = owner_in;
	name = name_in;
}

void Component::Update()
{
	// Do stuff
}

void Component::Start()
{
	// Do stuff
}
