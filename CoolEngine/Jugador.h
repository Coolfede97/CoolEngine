#pragma once
#include "GameObject.h"

class Jugador : public GameObject
{
public:
	double speed;
	void Update() override;
	void Draw() override;
	void Start() override;
};

