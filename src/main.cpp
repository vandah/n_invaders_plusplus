/**
 * @mainpage
 * @section Description
 * Last Change:11-Jun-2017.
 *
 * Created by Vanda Hendrychova
 */

#include "main.h"
#include "view.h"

view gui;

int main(int argc, char** argv)
{
  /// evaluate the commandline arguments
  get_opts(argc, argv);

  /// initialize the GUI
  gui.init();

  /// start the time ticks
  start_timer();

  /// initialize random sequence with system time
  srand(time(NULL));

  while (1) {
    sleep(1000);
  }
}

void start_timer()
{
  struct itimerval timer;

  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 1000000 / FPS;
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 1000000 / FPS;

  setitimer(ITIMER_REAL, &timer, NULL);

  struct sigaction action;

  action.sa_handler = &handle_timer; /* signal handler function */
  action.sa_flags = SA_RESTART;

  sigemptyset(&action.sa_mask);
  sigaddset(&action.sa_mask, SIGINT);

  sigaction(SIGALRM, &action, NULL);
}

void handle_timer(int sig) { gui.handle_timer(); }
