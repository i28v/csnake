#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>

void enableRawMode();
void disableRawMode();
int kbhit(void);
int getch(void);

#endif
