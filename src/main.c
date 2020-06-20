#include <unistd.h>
#include "Game.h"
#include "Input.h"

int main(void)
{
	
    system("clear");
	printf("\e[?25l");
	enableRawMode();
	struct Game game;
	gameInitGame(&game);
	while(game.gameOver != 1)
	{
		gameMainGameLoop(&game);
		usleep(83 * 1000);
	}	
	gameCleanUp(&game);
	disableRawMode();
  	tcflush(0, TCIFLUSH);
	printf("\e[?25h");
	return 0;
}
