#pragma once
using namespace std;
#include <string>
#include <vector>
#include "GameObject.h"
#include "TestPlayer.h"
#include "Vec2.h"
class Game
{
public:
	Game(int width, int height, int fps, string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool GameShouldClose() const;
	void Start();
	void Tick();

	static vector<GameObject> gameObjects;
	// Player Stuff
	TestPlayer player;

private:
	void Draw();
	void Update();
};