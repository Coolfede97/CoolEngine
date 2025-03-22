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
	player.position.x += player.speed * GetFrameTime();
}
