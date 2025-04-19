#include <iostream>
#include <string>
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
#include "Component.h"
#include <atomic>
#include <assert.h>
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


bool GameObject::RemoveIn(vector<GameObject*>& vector_in)
{
	for (int i = 0; i < vector_in.size(); i++)
	{
		if (vector_in[i]->ID == this->ID)
		{
			vector_in.erase(vector_in.begin() + i);
			return true;
		}
	}
	cout << "No se encontró el GameObject " << name << "al intentar eliminarlo del vector" << endl;
	return false;
}

bool GameObject::IsIn(vector<GameObject*>& vector_in)
{
	for (int i = 0; i < vector_in.size(); i++)
	{
		if (vector_in[i]->ID == this->ID)
		{
			return true;
		}
	}
	return false;
}


void GameObject::Destroy()
{
	vector<GameObject*>* gos = &Game::gameObjects;
	for (int i = 0; i < gos->size(); i++)
	{
		if ((*gos)[i]->ID == this->ID) gos->erase(gos->begin() + i);
	}
	if (children.size() > 0)
	{
		for (GameObject* child : children)
		{
			child->Destroy();
		}
		if (father != nullptr)
		{
			this->RemoveIn(father->children);
		}
	}
	delete this;
}

void GameObject::MakeFatherOf(GameObject*& child_in)
{
	assert(child_in->ID != ID, "A FATHER CAN'T BE ITS OWN CHILD");
	assert(!child_in->IsIn(children), "THE GAMEOBJECT CALLED " + name + " IS ALREADY THE FATHER OF " + child_in->name);
	assert(father != child_in, "THE GAMEOBJECT CALLED " + child_in->name + " IS THE FATHER OF " + name + ", SO " + name + "CAN'T BE THE FATHER OF " + child_in->name);
	children.push_back(child_in);
	child_in->father = this;
	
}

GameObject GameObject::operator=(const GameObject& other)
{
	transform = other.transform;
	name = other.name;
	return *this;
}

GameObject::GameObject(string name_in, GameObjectsTags gameObjectTag_in, bool active_in)
{
	transform = AddComponent<Transform>();
	name = name_in;
	active = active_in;
	renderingIndex = 0;
	startCalled = false;
	tag = gameObjectTag_in;
	lastID++;
	ID = lastID;
	Game::gameObjects.push_back(this);
}



