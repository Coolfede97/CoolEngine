#pragma once
#include "raylib.h"
class Assets
{
	struct Sprites
	{
		Texture2D timmy;
		Texture2D coolfede97;
		Texture2D ibor;
	};
	 void LoadSprites();
public:
	Sprites sprites;
	void LoadAssets();

};