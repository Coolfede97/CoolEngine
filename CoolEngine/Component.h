#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
class GameObject;

enum class ComponentOfType
{
	None,
	Transform,
	Renderer
};

class Component
{
public:
	Component(GameObject* owner_in, ComponentOfType type_in, string name_in);
	GameObject* owner;
	string name;
	ComponentOfType type;
	virtual void Update();
	virtual void Start();
	virtual ~Component() = default;

};