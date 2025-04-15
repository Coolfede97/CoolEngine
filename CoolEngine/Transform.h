#pragma once
#include "Vec2.h"
#include "Component.h"
class Transform : public Component
{
public:
	Transform();
	Vec2 position;
	Vec2 scale;
	Transform operator=(Transform other);
	Vec2 WorldPosition();
};