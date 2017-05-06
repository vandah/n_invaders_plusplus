#include <unistd.h>
#include <csignal>
#include <string>
#include <ncurses.h>
#ifndef GLOBALS
#define GLOBALS
extern void show_version();
extern void get_opts(int argc, char** argv);
extern void start_timer();
#endif
