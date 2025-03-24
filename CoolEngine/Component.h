#pragma once
#include <iostream>
using namespace std;
#include <string>
class GameObject;

enum class ComponentOfType
{
	Transform,
	Renderer
};

class Component
{
public:
	Component(GameObject* owner_in, string name_in);
	GameObject* owner;
	string name;

	virtual void Update();
	virtual void Start();
	virtual ~Component() = default;

};