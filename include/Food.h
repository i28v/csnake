#ifndef FOOD_H
#define FOOD_H

#include "Game.h"
#include "Snake.h"

struct Food
{
	int xpos, ypos, value;
	char symbol;
};

void foodInit(struct Food* food);
void foodUpdate(struct Food* food, struct Snake* snake, struct Game* game);
void foodDraw(struct Food* food, struct Game* game);

#endif
