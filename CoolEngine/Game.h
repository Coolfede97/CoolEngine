#pragma once
using namespace std;
#include <string>
#include <vector>
#include "GameObject.h"
#include "TestPlayer.h"
#include "Vec2.h"
#include "Jugador.h"
#include <string>
class Game
{
public:
	Game(int width, int height, int fps, string title);
	static Vec2 screenSize;
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool GameShouldClose() const;
	void Start();
	void Tick();

	static vector<GameObject*> gameObjects;
	// Player Stuff
private:
	void Draw();
	void Update();
};