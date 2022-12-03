#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <playground_backend_glfw.h>
#include <playground.h>
#include <time.h>
#include "gui/gui.h"
#include "game.h"
#include "snake.c"
#include "apple.c"

void game_init(Game* game)
{
    game->snake.x = 70 / 2;
    game->snake.y = 50 / 2;
    game->apple.x = 20;
    game->apple.y = 20;
    srand(time(0));
}

void game_update(Game* game)
{
    appleUpdate(game);
    snakeUpdate(game);
    im_print(0,0, "Score : %d", game->score);
}