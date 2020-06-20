#include "Game.h"

char map1[32][128] = 
{
		"###############################################################################################################################",
	    "#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"#                                                                                                                             #",
  		"#                                                                                                                             #",
		"#                                                                                                                             #",
		"###############################################################################################################################"
};


void gameInitGame(struct Game* game)
{
	game->gameOver = 0;
	for(int j = 0; j <= 31; j++)
	{
	    for(int i = 0; i <= 127; i++)
		{
			game->mapBuffer[j][i] = map1[j][i];
		}
	}
	game->snake = malloc(sizeof(struct Snake));
	snakeInit(game->snake);
}

void gameRenderBuffer(struct Game* game)
{
	printf("\033[0;0f");
	for(int j = 0; j <= 31; j++)
	{
		for(int i = 0; i <= 127; i++)
		{
			printf("%c", game->mapBuffer[j][i]);
		}
		if(j == 0)
		{
			printf("#");
		}
		printf("\n");
		printf(" ");
	}
}

void gameCheckInput(struct Game* game)
{
	if(kbhit())
	{
		char ch = getch();
		switch(ch)
		{
			case 'w':
				game->snake->snakeDirection = Up;
				break;
			case 's':
				game->snake->snakeDirection = Down;
				break;
			case 'a':
				game->snake->snakeDirection = Left;
				break;
			case 'd':
				game->snake->snakeDirection = Right;
				break;
			case 'g':
				game->snake->snakeLength += 1;
				break;
			case 'q':
				game->gameOver = 1;
			default:
				break;
		}
	}
}

void gameUpdateGame(struct Game* game)
{
	snakeUpdate(game->snake, game);
}

void gameDraw(struct Game* game)
{
	snakeDraw(game->snake, game);
	gameRenderBuffer(game);
}

void gameMainGameLoop(struct Game* game)
{
    gameCheckInput(game);
	gameUpdateGame(game);
	gameDraw(game);
}

void gameCleanUp(struct Game* game)
{
	free(game->snake);
}
