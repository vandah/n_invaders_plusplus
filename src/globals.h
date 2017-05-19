/**
 * \file globals.h
 * global includes and functions
 */

#ifndef GLOBALS
#define GLOBALS
#define VERSION "0.0.1-1"

#include <unistd.h>
#include <csignal>
#include <string>
#include <vector>
#include <iostream>
#include <ncurses.h>

///version info
extern void show_version();

/// evaluate command line parameters
extern void get_opts(int argc, char** argv);
#endif
