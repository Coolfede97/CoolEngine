#include <iostream>
using namespace std;
#include "Jugador.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vec2.h"
void Jugador::Update()
{
	transform.position += Vec2::Right() * speed;
}

void Jugador::Draw()
{

}

void Jugador::Start()
{

}
