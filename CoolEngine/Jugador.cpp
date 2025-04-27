#include <iostream>
using namespace std;
#include "Jugador.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vec2.h"
#include "raylib.h"
#include <string>

Jugador::Jugador()
{
	speed = 300;
}
void Jugador::Update()
{
	owner->transform->Move(Vec2::Right() * speed * GetFrameTime());
}

void Jugador::Start()
{
}

