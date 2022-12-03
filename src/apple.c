#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <playground_backend_glfw.h>
#include <playground.h>
#include <stdlib.h>
#include "gui/gui.h"
#include "game.h"

void appleReset(Game* game)
{
    im_print(game->apple.x, game->apple.y, "S");
    game->apple.x = rand() % 69 + 1;
    game->apple.y = rand() % 49 + 1;
}

void appleDraw(Game* game)
{
    im_print(game->apple.x, game->apple.y, "A");
}

void appleCollision(Game* game)
{
    if (game->snake.x == game->apple.x && game->snake.y == game->apple.y)
    {
        appleReset(game);
        game->score ++;
    }
}

void appleUpdate(Game* game)
{
    appleDraw(game);
    appleCollision(game);
}