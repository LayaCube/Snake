#pragma once
// Game data
typedef struct Game
{
    int scene;

    int x;
    int y;
    int direction; //1 = Up; 2 = Right; 3 = Down; 4 = Left;

    float timePassing;
    int clearScreenOrder;
} Game;

void game_update(Game* game);
void game_init(Game* game);