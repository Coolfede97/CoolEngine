#include "Game.h"
#include <raylib.h>
#include <assert.h>
#include <iostream>
#include "Vec2.h"
#include "TestPlayer.h"
#include <cmath>
using namespace std;

Game::Game(int width, int height, int fps, string title)
{
	assert(!GetWindowHandle());
	SetTargetFPS(fps);
	player = TestPlayer(Vec2(0.0, 150), 300, WHITE);
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
	DrawRectangle((int)player.position.x, (int)player.position.y, 50, 50, GREEN);
}

void Game::Update()
{
	for (GameObject GO : gameObjects)
	{
		GO.Update();
	}
	player.position += Vec2::Right() * player.speed * GetFrameTime();
}
