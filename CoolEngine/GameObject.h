#pragma once
using namespace std;
#include <string>
#include "Transform.h"
class GameObject
{
public:
	GameObject(Transform transform_in=Transform(), string name_in="newGameObject", bool active = true);
	Transform transform;
	string name;
	virtual void Start();
	virtual void Update();
	virtual void Draw();

	GameObject operator=(GameObject other);
};