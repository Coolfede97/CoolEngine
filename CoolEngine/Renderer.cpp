#include <iostream>
using namespace std;
#include "Renderer.h"
#include "Component.h"
#include "GameObject.h"
#include "raylib.h"


Renderer::Renderer(GameObject* owner_in, bool isCircle_in, Color color_in, string name_in)
	:Component(owner_in, name_in)
{
	isCircle = isCircle_in;
	color = color_in;
}

void Renderer::Update()
{
	Draw();
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
