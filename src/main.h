#ifndef MAIN
#define MAIN

#include "globals.h"
#include "view.h"
#include <sys/time.h>

extern view gui;

#define FPS 50

#define HISCORE_FILE "data/high_scores.txt"
#define BUNKERS_FILE "examples/bunkers.txt"
#define LVL1_FILE "examples/lvl1.txt"

#define LVL_CNT 5

int main(int argc, char** argv);

/// start timer and set time handler function
void start_timer();

/// inform the gui about time event
void handle_timer(int sig);

/// cleanup
void finish(int exit_code);

/// get high scores from a file
std::vector<std::pair<std::string, int>> get_hiscores();

std::vector<std::vector<int>> get_bunkers();
#endif
