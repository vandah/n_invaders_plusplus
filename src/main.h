#ifndef MAIN
#define MAIN

#include "globals.h"

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
