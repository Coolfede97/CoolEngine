#include <iostream>
using namespace std;
#include "Transform.h"
#include "Game.h"
#include "GameObject.h"
#include "Component.h"
Transform::Transform()
{
	position = Vec2::Zero();
	scale = Vec2::One();
}

Transform Transform::operator=(Transform other)
{	
	position = other.position;
	scale = other.scale;
	return *this;
}

Vec2 Transform::WorldPosition()
{
	Vec2 screenHalfSize = Vec2(Game::screenSize.x / 2, Game::screenSize.y / 2);
	if (owner->father != nullptr)
	{
		Vec2 fatherHalfSize = owner->father->transform->scale/2;
		return fatherHalfSize + owner->father->transform->WorldPosition() + position - scale / 2;
	}
	return screenHalfSize + position - scale / 2;
}
