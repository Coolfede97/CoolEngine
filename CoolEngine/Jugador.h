#pragma once
#include <iostream>
#include "GameObject.h"
#include <string>
#include "Game.h"
using namespace std;
class Jugador : public GameObject
{
public:
	Jugador(string name_in = "Jugador", bool active_in = true, double speed_in = 300)
		: GameObject(name_in, SceneGameObjects::Jugador, active_in), speed(speed_in){}

	double speed;
	void Update() override;
	void Draw() override;
	void Start() override;

};

