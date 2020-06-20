#include "Snake.h"

void snakeInit(struct Snake* snake)
{
	snake->snakeLength = 8;
	snake->snakeDirection = Right;
	snake->bodyXPos[0] = 63;
	snake->bodyYPos[0] = 15;
    snake->bodyXPos[1] = 62;
	snake->bodyYPos[1] = 15;
    snake->bodyXPos[2] = 61;
	snake->bodyYPos[2] = 15;
    snake->bodyXPos[3] = 60;
	snake->bodyYPos[3] = 15;
    snake->bodyXPos[4] = 59;
	snake->bodyYPos[4] = 15;
    snake->bodyXPos[5] = 58;
	snake->bodyYPos[5] = 15;
    snake->bodyXPos[6] = 57;
	snake->bodyYPos[6] = 15;
    snake->bodyXPos[7] = 56;
	snake->bodyYPos[7] = 15;
}

void snakeDraw(struct Snake* snake, struct Game* game)
{
	for(int i = 0; i < snake->snakeLength; i++)
	{
		if(i == 0)
		{
			game->mapBuffer[snake->bodyYPos[i]][snake->bodyXPos[i]] = '@';
		}
		else 
		{
			game->mapBuffer[snake->bodyYPos[i]][snake->bodyXPos[i]] = (char)'*'; 
		}
	}
}

void snakeUpdate(struct Snake* snake, struct Game* game)
{
	for(int i = snake->snakeLength; i > 0; i--)
	{
		game->mapBuffer[snake->bodyYPos[i]][snake->bodyXPos[i]] = ' ';
		snake->bodyXPos[i] = snake->bodyXPos[i-1];
		snake->bodyYPos[i] = snake->bodyYPos[i-1];
	}
	switch(snake->snakeDirection)
	{
		case Up:
			if(game->mapBuffer[snake->bodyYPos[0]-1][snake->bodyXPos[0]] == '#')
			{
				game->gameOver = 1;
				return;
			}
			else
			{
				snake->bodyYPos[0]--;
			}
			//game->mapBuffer[snake->bodyYPos[snake->snakeLength]+1][snake->bodyXPos[snake->snakeLength]] = ' ';
			break;
		case Down:
			if(game->mapBuffer[snake->bodyYPos[0]+1][snake->bodyXPos[0]] == '#')
			{
				game->gameOver = 1;
				return;
			}
			else 
			{
				snake->bodyYPos[0]++;
			}
			//game->mapBuffer[snake->bodyYPos[snake->snakeLength-1]][snake->bodyXPos[snake->snakeLength]] = ' ';
			break;
		case Left:
			if(game->mapBuffer[snake->bodyYPos[0]][snake->bodyXPos[0]-1] == '#')
			{
				game->gameOver = 1;
				return;
			}
			else 
			{
				snake->bodyXPos[0]--;
			}
			//game->mapBuffer[snake->bodyYPos[snake->snakeLength]][snake->bodyXPos[snake->snakeLength]+1] = ' ';
			break;
		case Right:
			if(game->mapBuffer[snake->bodyYPos[0]][snake->bodyXPos[0]+1] == '#')
			{
				game->gameOver = 1;
				return;
			}
			else
			{
				snake->bodyXPos[0]++;
			}
			//game->mapBuffer[snake->bodyYPos[snake->snakeLength]][snake->bodyXPos[snake->snakeLength]-1] = ' ';
			break;
		default:
			break;
	}
}
