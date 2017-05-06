#include "globals.hpp"
#include "view.hpp"
#include <sys/time.h>
#ifndef MAIN
#define MAIN

#define FPS 50

int main(int argc,char **argv);
void start_timer();
void handle_timer(int sig);
void finish();

#endif
