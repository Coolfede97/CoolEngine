#pragma once
#include "Vec2.h"

class Transform
{
public:
	Transform(Vec2 pos_in=Vec2::Zero(), Vec2 scale_in=Vec2::One());
	Vec2 position;
	Vec2 scale;

	Transform operator=(Transform other);
};