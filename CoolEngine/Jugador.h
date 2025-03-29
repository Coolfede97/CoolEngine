#pragma once
#include <iostream>
#include "GameObject.h"
#include <string>
#include "Game.h"
using namespace std;
class Jugador : public Component
{
public:
	Jugador(GameObject* owner_in, double speed_in = 300)
		: Component(owner_in), speed(speed_in){}

	double speed;
	void Update() override;
	void Start() override;

};

