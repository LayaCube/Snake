#pragma once

typedef struct Snake
{
    int x;
    int y;
    int direction; //1 = Up; 2 = Right; 3 = Down; 4 = Left;
} Snake;

typedef struct Apple
{
    int x;
    int y;
} Apple;

// Game data
typedef struct Game
{
    int scene;

    int score;
    float timePassing;
    int clearScreenOrder;

    Apple apple;
    Snake snake;
} Game;

void game_update(Game* game);
void game_init(Game* game);