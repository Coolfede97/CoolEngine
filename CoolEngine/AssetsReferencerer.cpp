#include "AssetsReferencerer.h"

void Assets::LoadAssets()
{
	LoadSprites();
}

void Assets::LoadSprites()
{
	sprites.coolfede97 = LoadTexture("Assets/Sprites/CoolFede97.png");
	sprites.timmy = LoadTexture("Assets/Sprites/Timmy.png");
	sprites.ibor = LoadTexture("Assets/Sprites/Ibor.png");
}
