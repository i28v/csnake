#ifndef SNAKE_H
#define SNAKE_H

#include "Game.h"

enum Direction
{
	Up=1, Down=2, Left=4, Right=8
};

struct Snake
{
	enum Direction snakeDirection;
	int snakeLength;
	int bodyXPos[3625];
	int bodyYPos[3625];
};

void snakeInit(struct Snake* snake );
void snakeUpdate(struct Snake* snake, struct Game* game);
void snakeDraw(struct Snake* snake, struct Game* game);
void snakeMove(struct Snake* snake, struct Game* game);

#endif /* SNAKE_H */
