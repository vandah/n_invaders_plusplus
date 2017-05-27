#ifndef MAIN
#define MAIN

#include "globals.h"
#include "view.h"
#include <sys/time.h>

extern view gui;

#define FPS 50
#define HISCORE_FILE "data/high_scores.txt"

int main(int argc, char** argv);

/// start timer and set time handler function
void start_timer();

/// inform the gui about time event
void handle_timer(int sig);

/// cleanup
void finish(int exit_code);

/// get high scores from a file
std::vector<std::pair<std::string, int>> get_hiscores();
#endif
