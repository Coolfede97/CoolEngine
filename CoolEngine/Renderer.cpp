#include <iostream>
using namespace std;
#include "RayLibTranslator.h"
#include "Renderer.h"
#include "Component.h"
#include "GameObject.h"
#include <assert.h>

void Renderer::UpdateSpriteScale(Texture2D& tex)
{
	tex.width = tex.width * size.x * aspectRatio.x * owner->transform->scale.x;
	tex.height = tex.height * size.y * aspectRatio.y * owner->transform->scale.y;
}

Renderer::Renderer()
{
	sprite = Game::assets.sprites.timmy;
	color = WHITE;
	size = {1,1};
	aspectRatio = { 1,1 };
}

void Renderer::Draw()
{
	Texture2D spriteCopy = sprite;
	Transform* myTransform = owner->transform;
	
	UpdateSpriteScale(spriteCopy);
	Vector2 drawPos = RayVec(myTransform->WorldPos() - Vec2(spriteCopy.width/2,spriteCopy.height/2));

	// That "1", represents that the Sprite is going to be drawn with its scale which has been modified
	// by UpdateSpriteScale(). Changing it would mean to change its scale again, so don't do it :v
	DrawTextureEx(spriteCopy, drawPos, owner->transform->rotation, 1, color);
}

