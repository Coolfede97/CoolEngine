#include <iostream>
using namespace std;
#include "Renderer.h"
#include "Component.h"
#include "GameObject.h"
#include "raylib.h"

Renderer::Renderer(GameObject* owner_in, bool isCircle_in, Color color_in, string name_in)
	:Component(owner_in, name_in)
{
	ownerTransform = &owner_in->transform;
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
		DrawCircle(ownerTransform->WorldPosition().x
			, ownerTransform->WorldPosition().y
			, ownerTransform->scale.x,
			color);
	}
	else
	{
		//cout << ownerTransform. << endl;
		DrawRectangle(ownerTransform->WorldPosition().x
			, ownerTransform->WorldPosition().y
			, ownerTransform->scale.x,
			ownerTransform->scale.y,
			color);
	}
}
