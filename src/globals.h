/**
 * \file globals.h
 * global includes and functions
 */

#ifndef GLOBALS
#define GLOBALS
#define VERSION "0.0.1-1"
#define AUTHOR "Vanda Hendrychova"

#include <csignal>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

/// version info
extern void show_version();

/// evaluate command line parameters
extern void get_opts(int argc, char** argv);

/// print high scores to stdout
extern void show_hiscores();
#endif
