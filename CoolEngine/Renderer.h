#pragma once
#include "Component.h"
#include <string>
#include "raylib.h"
#include "Vec2.h"
#include "Transform.h"
class Renderer : public Component
{
public:
	Renderer();
	void Draw() override;
	bool isCircle;
	Color color;
};