#pragma once
#include <iostream>
#include "GameObject.h"
#include <string>
#include "Game.h"
using namespace std;
class Jugador : public Component
{
public:
	Jugador();

	double speed;
	void Update() override;
	void Start() override;

};

