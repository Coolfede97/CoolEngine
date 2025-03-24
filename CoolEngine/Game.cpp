#include <iostream>
#include "Game.h"
#include <raylib.h>
#include <assert.h>
#include "Vec2.h"
#include "TestPlayer.h"
#include <cmath>
#include "Jugador.h"
#include <vector>
#include "GameObject.h"
#include <string>
#include "Renderer.h"
using namespace std;

Vec2 Game::screenSize = Vec2(0, 0);
vector<GameObject*> Game::gameObjects = {};
Game::Game(int width, int height, int fps, string title)
{
	assert(!GetWindowHandle());
	SetTargetFPS(fps);
	Game::screenSize = Vec2(width, height);
	
	Start();
	InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Start()
{
	// Probably Create GameObjects and Add them to gameObjects
	gameObjects.push_back(new Jugador());
	gameObjects[0]->components.push_back(new Renderer(gameObjects[0],false));
}

void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Game::Draw()
{
	ClearBackground(BLACK);
	//DrawRectangle((int)player.position.x, (int)player.position.y, 50, 50, GREEN);
}

void Game::Update()
{
	for (GameObject* GO : gameObjects)
	{
		if (GO == nullptr)
		{
			cout << "PUNTERO NULL" << endl;
			continue;
		}
		GO->Update();
	}
	//player.position += Vec2::Right() * player.speed * GetFrameTime();
}
