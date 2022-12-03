#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <playground_backend_glfw.h>
#include <playground.h>
#include "gui/gui.h"
#include "game.h"

void snakeDraw(Game* game)
{
    im_print(game->snake.x, game->snake.y, "S");
}

void snakeMovement(Game* game)
{
    if (game->timePassing > 0.3f)
    {
        game->timePassing = 0;
        switch (game->snake.direction)
        {
        case 1:
            game->snake.y -= 1;
            break;
        
        case 2:
            game->snake.x += 1;
            break;
        
        case 3:
            game->snake.y += 1;
            break;

        case 4:
            game->snake.x -= 1;
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
        game->snake.direction = 1;
    if (pg_io_key_down(GLFW_KEY_RIGHT))
        game->snake.direction = 2;
    if (pg_io_key_down(GLFW_KEY_DOWN))
        game->snake.direction = 3;
    if (pg_io_key_down(GLFW_KEY_LEFT))
        game->snake.direction = 4;
}

int snakeUpdate(Game* game)
{
    snakeControls(game);
    snakeMovement(game);
    snakeDraw(game);
    
}
