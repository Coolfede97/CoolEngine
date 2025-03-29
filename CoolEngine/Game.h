#pragma once
using namespace std;

enum class SceneGameObjects
{
	Untagged,
	Jugador
};

#include <string>
#include <vector>
#include "CoolEngine.h"
#include <string>
#include <unordered_map>


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