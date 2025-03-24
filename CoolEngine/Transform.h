#pragma once
#include "Vec2.h"
#include "Component.h"
class Transform : public Component
{
public:
	Transform(GameObject* owner_in, Vec2 pos_in = Vec2::Zero(), Vec2 scale_in = Vec2::One());
	Vec2 position;
	Vec2 scale;
	GameObject* owner;
	Transform operator=(Transform other);
	Vec2 WorldPosition();
};