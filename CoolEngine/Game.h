#pragma once
using namespace std;
#include <string>
#include <vector>
#include "GameObject.h"
#include "TestPlayer.h"
#include "Vec2.h"
#include "Jugador.h"
#include <string>
#include <unordered_map>

enum class SceneGameObjects
{
	Untagged,
	Jugador
};

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
	//static unordered_map<SceneGameObjects, GameObject*> gameObjects;
	// Player Stuff
private:
	void Draw();
	void Update();
};