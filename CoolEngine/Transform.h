#pragma once
#include "Vec2.h"
#include "Component.h"

class Transform : public Component
{
public:
	Transform();
	Vec2 position;
	Vec2 scale;
	double rotation;
	Transform operator=(Transform other);
	Vec2 LocalPos();
	Vec2 WorldPos();
	void Move(Vec2 velocity);
};