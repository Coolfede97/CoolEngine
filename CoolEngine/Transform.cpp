#include <iostream>
using namespace std;
#include "Transform.h"
#include "Game.h"
Transform::Transform(Vec2 pos_in, Vec2 scale_in)
{
	position = pos_in;
	scale = scale_in;
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
	return screenHalfSize + position;
}
