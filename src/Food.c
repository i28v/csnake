#include "Food.h"

void foodInit(struct Food* food)
{
    food->xpos = rand() % 125 + 1;
    food->ypos = rand() % 30 + 1;
    food->value = 1;
    food->symbol = '%';
}

void foodUpdate(struct Food* food, struct Snake* snake, struct Game* game)
{
    if (snake->bodyXPos[0] == food->xpos && snake->bodyYPos[0] == food->ypos)
    {
        snake->snakeLength++;
        game->score += food->value;
        food->xpos = rand() % 125 + 1;
        food->ypos = rand() % 30 + 1;
    }
}

void foodDraw(struct Food* food, struct Game* game)
{
    game->mapBuffer[food->ypos][food->xpos] = food->symbol;
}
