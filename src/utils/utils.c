#pragma once
#include "../game.h"
void clearScreen(Game* game)
{
    if (game->clearScreenOrder)
    {
        game->clearScreenOrder = 0;
        pg_clear_all();
    }
}
