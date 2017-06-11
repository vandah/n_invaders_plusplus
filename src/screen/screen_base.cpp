#include "screen_base.h"
#include "../view.h"

screen_base::screen_base()
    : win(NULL)
    , midcol(0)
    , midrow(0)
{
  rows = gui.rows;
  cols = gui.cols;
}

void screen_base::scr_clear() const
{
  clear();
  noecho();
  cbreak();
  refresh();
  box(win, 0, 0);
  wrefresh(win);
}

void screen_base::handle_timer()
{
  redraw();
  if (win) {
    wmove(win, 0, 0);
  }
  read_input();
}

void screen_base::read_input()
{
  if (gui.current_screen && gui.current_screen->win) {
    gui.current_screen->handle_event(wgetch(gui.current_screen->win));
  }
}

void screen_base::handle_event(int event)
{
  switch (event) {
  case 'h':
  case 'a':
  case KEY_LEFT:
    key_left();
    break;

  case 'j':
  case 's':
  case KEY_DOWN:
    key_down();
    break;

  case 'k':
  case 'w':
  case KEY_UP:
    key_up();
    break;

  case 'l':
  case 'd':
  case KEY_RIGHT:
    key_right();
    break;

  case 'p':
    key_pause();
    break;

  case 'q':
    key_quit();
    break;

  case 10:
  case KEY_ENTER:
    key_enter();
    break;

  case 8:
  case 127:
  case KEY_BACKSPACE:
    key_backspace();
    break;

  case ' ':
    key_space();

  default:
    break;
  }
}

void screen_base::key_up() {}

void screen_base::key_down() {}

void screen_base::key_left() {}

void screen_base::key_right() {}

void screen_base::key_enter() {}

void screen_base::key_space() {}

void screen_base::key_backspace() {}

void screen_base::key_quit() {}

void screen_base::key_pause() {}

screen_base::~screen_base()
{
  delwin(win);
  win = NULL;
  endwin();
}

void screen_base::switch_screen(int new_scr) const
{
  gui.switch_screen(new_scr);
}
