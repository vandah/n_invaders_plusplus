/**
 * \file globals.hpp
 * global includes and functions
 */

#include <unistd.h>
#include <csignal>
#include <string>
#include <ncurses.h>
#ifndef GLOBALS
#define GLOBALS

///version info
extern void show_version();

/// evaluate command line parameters
extern void get_opts(int argc, char** argv);
#endif
