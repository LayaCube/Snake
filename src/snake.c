#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <playground_backend_glfw.h>
#include <playground.h>
#include "gui/gui.h"
#include "game.h"

void snakeDraw(Game* game)
{
    im_print(game->x, game->y, "S");
}

void snakeMovement(Game* game)
{
    if (game->timePassing > 0.3f)
    {
        game->timePassing = 0;
        switch (game->direction)
        {
        case 1:
            game->y -= 1;
            break;
        
        case 2:
            game->x += 1;
            break;
        
        case 3:
            game->y += 1;
            break;

        case 4:
            game->x -= 1;
            break;

        default:
            break;
        }
        game->clearScreenOrder = 1;
    }
}

void snakeControls(Game* game)
{
    if (pg_io_key_down(GLFW_KEY_UP))
        game->direction = 1;
    if (pg_io_key_down(GLFW_KEY_RIGHT))
        game->direction = 2;
    if (pg_io_key_down(GLFW_KEY_DOWN))
        game->direction = 3;
    if (pg_io_key_down(GLFW_KEY_LEFT))
        game->direction = 4;
}

int snakeUpdate(Game* game)
{
    snakeControls(game);
    snakeMovement(game);
    snakeDraw(game);
    
}
