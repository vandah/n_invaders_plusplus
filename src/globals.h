/**
 * \file globals.h
 * global includes and functions
 */

#ifndef GLOBALS
#define GLOBALS

/// manipulation with files
#include <fstream>

/// output formatting
#include <iomanip>

/// stringstream
#include <sstream>

/// cout
#include <iostream>

/// GUI
#include <ncurses.h>

/// timer
#include <csignal>

/// timer + random
#include <sys/time.h>

/// sleep
#include <unistd.h>

#include <string>

#include <vector>

/// sort
#include <algorithm>

#define VERSION "1.0.0-1"
#define AUTHOR "Vanda Hendrychova"

#define FPS 40

/// indicates the need for resizing the screen
#define ERROR_SMALL_SCREEN 2

/// the file is empty and should not be
#define ERROR_EMPTY_FILE 3

/// the file could not have been loaded because of an unknown error
#define ERROR_CORRUPTED_FILE 4

/// filename for the file with high scores
#define HISCORE_FILE hiscore_file

/// file to load bunkers from
#define BUNKERS_FILE bunkers_file

/// filename for level x
#define LVL_FILE(x) levels[x]

/// game over ascii art
#define GAME_OVER_FILE game_over_file

/// game logo
#define LOGO_FILE logo_file

/// high score ascii art
#define WINNER_FILE winner_file

/// help
#define HELP_FILE "help.txt"

#define SCREEN_MENU 0
#define SCREEN_GAME 1
#define SCREEN_HISCORE 2
#define SCREEN_INSTRUCTIONS 3
#define SCREEN_QUIT 4
#define SCREEN_UNDEF 5

/// max level count
#define LVL_CNT 5

/// default number of lives
#define DEFAULT_LIVES 3

/// forward declaration of a class used for GUI
class view;

/// array of filenames for different levels
extern std::vector<std::string> levels;

/// file to load bunkers from
extern std::string bunkers_file;

/// filename for the file with high scores
extern std::string hiscore_file;

/// game over ascii art
extern std::string game_over_file;

/// game logo
extern std::string logo_file;

/// high score ascii art
extern std::string winner_file;

/// graphical user interface
extern view gui;

/// indicates whether the game is still running
extern bool GameOver;

/// version info (stdout)
extern void show_version();

/// evaluate command line parameters
extern void get_opts(int argc, char** argv);

/// print high scores to stdout
extern void show_hiscores();

/// show what is inside the bunkers file (stdout)
void show_bunkers();

/// get high scores from a file
std::vector<std::pair<std::string, int>> get_hiscores();

/// get integers from file
std::vector<std::vector<int>> get_data(std::string file);

/// get bunkers from file
std::vector<std::vector<int>> get_bunkers();

/// load strings from file
std::vector<std::string> load_lines(std::string file);

/// exit with the given exit code
void finish(int exit_code);
#endif
