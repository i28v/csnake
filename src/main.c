#include <unistd.h>
#include "Game.h"
#include "Input.h"

int main(void)
{
	
    srand(time(NULL)); // set seed to system time 
	system("clear"); // clear the screen
	printf("\e[?25l"); // hide cursor
	enableRawMode(); // prevent keys getting pressed from being printed onto the screen
	struct Game game; // create the game structure
	gameInitGame(&game); // initialize the game structure
	while(game.gameOver != 1) // do the main game loop while gameover is not equal to true (1)
	{
		gameMainGameLoop(&game);
		usleep(83 * 1000);
	}	
	gameCleanUp(&game); // delete the game's variables from memory
	disableRawMode(); // reenable pressed keys showing up on the screen
  	tcflush(0, TCIFLUSH); // prevent pressed keys from playing the game from showing up when the bash terminal opens
	printf("\e[?25h"); // show the cursor
	return 0; // exit the program
}
