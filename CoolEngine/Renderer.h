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

	Vec2 size;
	Vec2 aspectRatio;
	Color color;
	Texture2D sprite;

	void UpdateSpriteScale(Texture2D& tex);
};