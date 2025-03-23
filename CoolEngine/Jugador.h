#pragma once
#include <iostream>
#include "GameObject.h"
#include <string>
using namespace std;
class Jugador : public GameObject
{
public:
	Jugador(Transform transform_in = Transform({ 0,0 }, {50,50}), string name_in = "Jugador", bool active = true, double speed_in = 300)
		: GameObject(transform_in, name_in, active), speed(speed_in){}

	double speed;
	void Update() override;
	void Draw() override;
	void Start() override;

};

