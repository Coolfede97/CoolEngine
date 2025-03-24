#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Transform.h"
#include "Component.h"
#include <unordered_map>
#include <vector>
class GameObject
{
public:
	GameObject(string name_in="newGameObject", bool active = true);
	Transform* transform;
	string name;
	//vector<Component*> components;
	unordered_map<ComponentOfType, Component*> components;
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	
	virtual ~GameObject() = default;
	GameObject operator=(const GameObject& other);
};