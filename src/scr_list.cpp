#include "scr_list.h"
#include "main.h"

scr_list::scr_list()
    : selected_idx(0)
{
  win = newwin(gui.rows - 1, gui.cols - 1, 1, 1);
  keypad(win, TRUE);
  midcol = gui.cols;
  current_row = gui.rows;
}

scr_list::~scr_list() {}

void scr_list::draw_list() const
{
  clear();
  noecho();
  cbreak();
  refresh();
  //    midcol = COLS/2;
  //    current_row
  box(win, 0, 0);
  wrefresh(win);
  mvprintw(24, 14, "selected: %d, from: %d", selected_idx,
      items.size()); // FIXME souradnice jsou random
  //    border(win);
}

void scr_list::handle_timer()
{
  redraw();
  handle_event(wgetch(win));
}

void scr_list::handle_event(int event)
{
  switch (event) {
  case 'l':
  case 10:
  case KEY_ENTER:
    //            gui.switch_screen(items[selected_idx].second);
    break;
  case 'k':
  case KEY_UP:
    if (items.size()) {
      selected_idx--;
      selected_idx %= items.size();
    }
    break;
  case 'j':
  case KEY_DOWN:
    selected_idx++;
    selected_idx %= items.size();
    break;
  case 'h':
  case 8:
  case 127:
  case KEY_BACKSPACE:
    selected_idx++;
    selected_idx %= items.size();
    gui.switch_screen(back);
    break;
  default:
    break;
  }
}
