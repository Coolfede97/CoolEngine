#pragma once
#include "Component.h"
#include <string>
#include "raylib.h"
class Renderer : public Component
{
public:
	Renderer(GameObject* owner_in, string name_in = "Renderer", Color color_in = WHITE)
		: Component(owner_in, name_in), color(color_in) {}

	void Update() override;
	void Draw();
	Color color;
};