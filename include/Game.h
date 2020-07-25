#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Snake.h"
#include "Food.h"
#include "Input.h"
#include "MapData.h"

#define FOOD_COUNT 16

extern char map1[32][128];

struct Game
{
	char mapBuffer[32][128];
	int score;
    int gameOver;
	struct Snake* snake;
	struct Food* food[FOOD_COUNT];
};

void gameInitGame(struct Game* game);
void gameMainGameLoop(struct Game* game);
void gameCheckInput(struct Game* game);
void gameUpdateGame(struct Game* game);
void gameDraw(struct Game* game);
void gameRenderBuffer(struct Game* game);
void gameCleanUp(struct Game* game);

#endif /* GAME_H */
