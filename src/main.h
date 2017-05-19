#ifndef MAIN
#define MAIN

#include "globals.h"
#include "view.h"
#include <sys/time.h>

extern view gui;

#define FPS 50

int main(int argc,char **argv);

///start timer and set time handler function
void start_timer();

///inform the gui about time event
void handle_timer(int sig);

///cleanup
void finish(int exit_code);

#endif
