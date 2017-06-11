#include "view.h"
#include "screen/scr_game.h"
#include "screen/scr_hiscore.h"
#include "screen/scr_instructions.h"
#include "screen/scr_menu.h"

view::view()
    : cols(0)
    , rows(0)
    , current_screen(NULL)
    , scr_main(NULL)
{
}

void view::init()
{
  scr_main = initscr();
  rows = LINES;
  cols = COLS;

  if (rows < 30 || cols < 30) {
    std::cout << ""
              << "\033[0;31m"
              << "ERROR: "
              << "\033[0m"
              << "SCREEN TOO SMALL" << std::endl;

    finish(ERROR_SMALL_SCREEN);
  }

  start_color();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);
  init_pair(7, COLOR_RED, COLOR_BLACK);

  bkgd(COLOR_PAIR(1));

  keypad(stdscr, TRUE);
  keypad(scr_main, TRUE);

  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  refresh();
  current_screen = new scr_menu;
}

view::~view()
{
  delwin(scr_main);
  delwin(stdscr);
  endwin();
}

void view::switch_screen(int s)
{
  screen_base* tmp_screen = current_screen;

  switch (s) {
  case SCREEN_MENU:
    current_screen = new scr_menu;
    break;

  case SCREEN_GAME:
    current_screen = new scr_game;
    break;

  case SCREEN_HISCORE:
    current_screen = new scr_hiscore;
    break;

  case SCREEN_INSTRUCTIONS:
    current_screen = new scr_instructions;
    break;

  case SCREEN_QUIT:
    current_screen = NULL;
    delete tmp_screen;
    finish(0);
    return;

  default: /*NO DEFINED SCREEN*/
    return;
  }

  current_screen->redraw();

  delete tmp_screen;
}

void view::handle_timer() { current_screen->handle_timer(); }
