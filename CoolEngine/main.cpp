#include <iostream>
#include <raylib.h>
#include "Game.h"
#include <vector>
using namespace std;
int main()
{
    Game game(854, 480, 60, "Title");
    while (!WindowShouldClose())
    {
        game.Tick();
    }
    return 0;
}