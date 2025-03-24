#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "Transform.h"
#include "Component.h"
#include <vector>
class GameObject
{
public:
	GameObject(Transform transform_in=Transform(), string name_in="newGameObject", bool active = true);
	Transform transform;
	string name;
	vector<Component*> components;
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	
	virtual ~GameObject() = default;
	GameObject operator=(GameObject other);
};