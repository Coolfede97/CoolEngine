#pragma once
using namespace std;

enum class GameObjectsTags
{
	Untagged,
	Jugador
};


#include <string>
#include <vector>
#include "CoolEngine.h"
#include <string>
#include <unordered_map>
#include <algorithm>

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
	static Assets assets;
private:
	void Draw();
	void Update();
};
