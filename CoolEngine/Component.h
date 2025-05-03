#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include "AssetsReferencerer.h"
class GameObject;

class Component
{
public:
	Component();
	GameObject* owner;
	virtual void Update();
	virtual void Start();
	virtual void Draw();
	virtual ~Component() = default;
};