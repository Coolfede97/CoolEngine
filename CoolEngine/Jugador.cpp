#include <iostream>
using namespace std;
#include "Jugador.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vec2.h"
#include "raylib.h"
#include <string>
void Jugador::Update()
{
	GameObject::Update();
	transform->position += Vec2::Right() * speed * GetFrameTime();
}

void Jugador::Draw()
{
	//DrawRectangle(transform->WorldPosition().x, transform->WorldPosition().y, transform->scale.x, transform->scale.y, GREEN);
}

void Jugador::Start()
{

}

