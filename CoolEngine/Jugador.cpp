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
	owner->transform->position += Vec2::Right() * speed * GetFrameTime();
}

void Jugador::Start()
{

}

