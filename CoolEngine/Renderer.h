#pragma once
#include "Component.h"
#include <string>
#include "raylib.h"
#include "Vec2.h"
#include "Transform.h"
class Renderer : public Component
{
public:
	/*Renderer(GameObject* owner_in, bool isCircle_in, Color color_in = WHITE, string name_in = "Renderer")
		: Component(owner_in, name_in), isCircle(isCircle_in), color(color_in) {}*/
	Renderer(GameObject* owner_in, bool isCircle_in, Color color_in = WHITE, string name_in = "Renderer");
	void Update() override;
	void Draw();
	bool isCircle;
	Color color;
};