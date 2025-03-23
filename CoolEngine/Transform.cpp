#include <iostream>
using namespace std;
#include "Transform.h"

Transform::Transform(Vec2 pos_in, Vec2 scale_in)
{
	position = pos_in;
	scale = scale_in;
}

Transform Transform::operator=(Transform other)
{	
	position = other.position;
	scale = other.scale;
}
