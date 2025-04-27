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

Vec2 Transform::LocalPos()
{
	return position;
}

Vec2 Transform::WorldPos()
{
	Vec2 screenHalfSize = Vec2(Game::screenSize.x / 2, Game::screenSize.y / 2);
	if (owner->father != nullptr)
	{
		Vec2 fatherHalfSize = owner->father->transform->scale/2;
		return fatherHalfSize + owner->father->transform->WorldPos();
	}
	return screenHalfSize + position;
}

void Transform::Move(Vec2 velocity)
{
	position += velocity;
}
