#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <playground_backend_glfw.h>
#include <playground.h>
#include "gui/gui.h"
#include "game.h"
#include "snake.c"

void game_init(Game* game)
{
    game->x = 70 / 2;
    game->y = 50 / 2;
}

void game_update(Game* game)
{
    
    snakeUpdate(game);
}