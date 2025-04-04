#include <iostream>
using namespace std;
#include "Renderer.h"
#include "Component.h"
#include "GameObject.h"
#include "raylib.h"


Renderer::Renderer()
{
	isCircle = false;
	color = WHITE;
}

void Renderer::Draw()
{
	if (isCircle)
	{
		DrawCircle(owner->transform->WorldPosition().x
			, owner->transform->WorldPosition().y
			, owner->transform->scale.x/2,
			color);
	}
	else
	{
		//cout << ownerTransform. << endl;
		DrawRectangle(owner->transform->WorldPosition().x
			, owner->transform->WorldPosition().y
			, owner->transform->scale.x,
			owner->transform->scale.y,
			color);
	}
}
