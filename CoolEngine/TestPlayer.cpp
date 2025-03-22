#include "Game.h"
#include <assert.h>
#include <iostream>
#include "raylib.h"
#include "Vec2.h"
#include "TestPlayer.h"
using namespace std;


TestPlayer::TestPlayer(Vec2 pos_in, double speed_in, Color color_in)
{
    position = pos_in;
    color = color_in;
    speed = speed_in;
}
