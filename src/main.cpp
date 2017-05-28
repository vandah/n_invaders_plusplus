/**
 * @mainpage
 * @section Description
 * Last Change:28-May-2017.
 * delsi popis
 *
 * Created by Vanda Hendrychova
 */

#include "main.h"

view gui;

int main(int argc, char** argv)
{
  /// evaluate the commandline arguments
  get_opts(argc, argv);

  /// initialize the GUI
  gui.init();

  /// start the time ticks
  start_timer();

  while (1) {
    //    gui.read_input();
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

void finish(int exit_code) { exit(exit_code); }

std::vector<std::pair<std::string, int>> get_hiscores()
{
  std::vector<std::pair<std::string, int>> hiscores;
  std::string name;
  int score;

  std::ifstream input(HISCORE_FILE, std::ios::in);

  if (!input.fail()) {
    while (input >> name >> score) {
      hiscores.push_back({ name, score });
    }
  }

  return hiscores;
}
