#ifndef MAIN
#define MAIN

#include "globals.h"

int main(int argc, char** argv);

/// start timer and set time handler function
void start_timer();

/// inform the gui about time event
void handle_timer(int sig);

#endif
