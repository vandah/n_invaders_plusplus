/**
 * \file globals.h
 * global includes and functions
 */

#ifndef GLOBALS
#define GLOBALS
#define VERSION "0.0.1-1"
#define AUTHOR "Vanda Hendrychova"

#define FPS 40

#define ERROR_SMALL_SCREEN 2

#define HISCORE_FILE "data/high_scores.txt"
#define BUNKERS_FILE "examples/bunkers.txt"
#define LVL_FILE(x) "examples/lvl" + std::to_string(x) + ".txt"
#define GAME_OVER_FILE "examples/game_over.txt"

#define SCREEN_MENU 0
#define SCREEN_GAME 1
#define SCREEN_HISCORE 2
#define SCREEN_INSTRUCTIONS 3
#define SCREEN_QUIT 4
#define SCREEN_UNDEF 5

#define LVL_CNT 5
#define DEFAULT_LIVES 3

#include <csignal>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <ncurses.h>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <vector>
#include <algorithm>

class view;

extern view gui;

extern bool GameOver;

/// version info
extern void show_version();

/// evaluate command line parameters
extern void get_opts(int argc, char** argv);

/// print high scores to stdout
extern void show_hiscores();

void show_bunkers();

/// get high scores from a file
std::vector<std::pair<std::string, int>> get_hiscores();

std::vector<std::vector<int>> get_data(std::string file);

std::vector<std::vector<int>> get_bunkers();

/// cleanup
void finish(int exit_code);

#endif
