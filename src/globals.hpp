#include <unistd.h>
#include <csignal>
#include <string>
#include <ncurses.h>
#ifndef GLOBALS
#define GLOBALS
extern void show_version();
/// evaluate command line parameters
extern void get_opts(int argc, char** argv);
#endif
