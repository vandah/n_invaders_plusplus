#include "view.h"
#include "screen/scr_game.h"
#include "screen/scr_hiscore.h"
#include "screen/scr_menu.h"
#include "screen/scr_settings.h"
#include "screen/screen_base.h"

view::view()
    : cols(0)
    , rows(0)
    , scr_main(NULL)
    , current_screen(NULL)
{
}

void view::init()
{
  scr_main = initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);
  bkgd(COLOR_PAIR(1)); // Green Text on a White Screen
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
  keypad(scr_main, TRUE);
  rows = LINES;
  cols = COLS;
  refresh();
  current_screen = new scr_menu;
}

view::~view() {}

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
  case SCREEN_SETTINGS:
    current_screen = new scr_settings;
    break;
  case SCREEN_QUIT:
    delete tmp_screen;
    finish(0);
    break;
  default: /*NO DEFINED SCREEN*/
    return;
  }
  delete tmp_screen;
}

void view::read_input() {} // TODO

// void view::refresh(){} //T0DO

void view::handle_timer() { current_screen->handle_timer(); }
