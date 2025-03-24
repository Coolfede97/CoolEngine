#pragma once
#include <iostream>
#include "GameObject.h"
#include <string>
using namespace std;
class Jugador : public GameObject
{
public:
	Jugador(string name_in = "Jugador", bool active = true, double speed_in = 300)
		: GameObject(name_in, active), speed(speed_in){}

	double speed;
	void Update() override;
	void Draw() override;
	void Start() override;

};

