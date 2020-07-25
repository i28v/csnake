#include "Game.h"

char map1[32][128] = MAP1;

void gameInitGame(struct Game* game)
{
    game->gameOver = 0;
    game->score = 8;
    for (int j = 0; j <= 31; j++)
    {
        for (int i = 0; i <= 127; i++)
        {
            game->mapBuffer[j][i] = map1[j][i];
        }
    }
    game->snake = malloc(sizeof(struct Snake));
    for (int i = 0; i < FOOD_COUNT - 1; i++)
    {
        game->food[i] = malloc(sizeof(struct Food));
    }
    snakeInit(game->snake);
    for (int i = 0; i < FOOD_COUNT - 1; i++)
    {
        foodInit(game->food[i]);
    }
}

void gameRenderBuffer(struct Game* game)
{
    printf("\033[0;0f");
    for (int j = 0; j <= 31; j++)
    {
        for (int i = 0; i <= 127; i++)
        {
            printf("%c", game->mapBuffer[j][i]);
        }
        if (j == 0)
        {
            printf("#");
        }
        printf("\n");
        printf(" ");
    }
    printf("\n\n Score: %i", game->score);
}

void gameCheckInput(struct Game* game)
{
    if (kbhit())
    {
        char ch = getch();
        if (ch == '\033')
        {
            getch();
            char ch2 = getch();
            switch (ch2)
            {
                case 'A':
                    if (game->snake->snakeDirection != Down)
                        game->snake->snakeDirection = Up;
                    break;
                case 'B':
                    if (game->snake->snakeDirection != Up)
                        game->snake->snakeDirection = Down;
                    break;
                case 'D':
                    if (game->snake->snakeDirection != Right)
                        game->snake->snakeDirection = Left;
                    break;
                case 'C':
                    if (game->snake->snakeDirection != Left)
                        game->snake->snakeDirection = Right;
                default:
                    break;
            }
        }
        else if (ch == 'q')
        {
            game->gameOver = 1;
        }
    }
}

void gameUpdateGame(struct Game* game)
{
    snakeUpdate(game->snake, game);
    for (int i = 0; i < FOOD_COUNT - 1; i++)
    {
        foodUpdate(game->food[i], game->snake, game);
    }
}

void gameDraw(struct Game* game)
{
    for (int i = 0; i < FOOD_COUNT - 1; i++)
    {
        foodDraw(game->food[i], game);
    }
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
    for (int i = 0; i < FOOD_COUNT - 1; i++)
    {
        free(game->food[i]);
    }
}
