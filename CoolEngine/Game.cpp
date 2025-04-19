#include <iostream>
#include <raylib.h>
#include <assert.h>
#include "CoolEngine.h"
#include <cmath>
#include <vector>
#include <string>
using namespace std;

Vec2 Game::screenSize = Vec2(0, 0);
vector<GameObject*> Game::gameObjects{};
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

// Called before update
// Equivalent to the hierarchy of Unity. Used for set up
void Game::Start()
{
	GameObject* newGOR = new GameObject();
	newGOR->tag = GameObjectsTags::Jugador;
	newGOR->transform->scale = Vec2(100, 50);
	newGOR->AddComponent<Renderer>();
	newGOR->GetComponent<Renderer>()->color = RED;

	GameObject* newGO = new GameObject();
	newGO->renderingIndex = 1;
	newGO->tag = GameObjectsTags::Jugador;
	newGO->transform->scale = Vec2(50, 50);
	newGO->AddComponent<Renderer>();
	newGO->GetComponent<Renderer>()->color = GREEN;
	newGO->AddComponent<Jugador>();
	newGO->MakeFatherOf(newGOR);
	newGOR->MakeChildOf(newGO);

	newGOR->Destroy();
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
	vector<GameObject*> GOsToDraw = gameObjects;
	sort(GOsToDraw.begin(), GOsToDraw.end(), [](GameObject* a, GameObject* b)
		{
			return a->renderingIndex < b->renderingIndex;
		});
	ClearBackground(BLACK);
	for (auto& GO : GOsToDraw)
	{
		if (GO == nullptr)
		{
			cout << "PUNTERO NULL" << endl;
			continue;
		}
		GO->Draw();
	}
}

// Calls every object's Update in the scene, but no the ones from objects created in this frame
void Game::Update()
{
	vector<GameObject*> updateGOS = gameObjects;
	for (auto& GO : updateGOS)
	{
		if (GO == nullptr)
		{
			cout << "NULL POINTER" << endl;
			continue;
		}
		GO->Update();
	}
}

