#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>
#include <unistd.h>

#define CLEAR() printf("\033[2J") 
#define RESET_CURSOR() printf("\033[H")

#endif /* CONSOLE_H */