#include "scr_list.h"
#include "../main.h"

scr_list::scr_list()
    : items(std::vector<std::pair<std::string, int>>{
          { "Go back", SCREEN_MENU }, { "Or also back", SCREEN_MENU } })
    , selected_idx(0)
    , back(SCREEN_MENU)
    , screen_title("")
{
  win = newwin(gui.rows - 1, gui.cols - 1, 1, 1);
  keypad(win, TRUE);
  midcol = gui.cols / 2;
  midrow = gui.rows / 2;
}

scr_list::~scr_list() {}

void scr_list::draw_list() const
{
  clear();
  noecho();
  cbreak();
  refresh();
  box(win, 0, 0);
  wrefresh(win);

  int current_row = midrow - items.size() / 2;
  for (unsigned int i = 0; i < items.size(); ++i) {
    attron(COLOR_PAIR(1 + (i == selected_idx)));

    mvprintw(current_row, midcol - (items[i].first.length() / 2), " %s ",
        items[i].first.c_str());

    current_row += 2;
  }
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
    gui.switch_screen(items[selected_idx].second);
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
    gui.switch_screen(back);
    break;
  default:
    break;
  }
}

void scr_list::redraw() const
{
  draw_list();
  refresh();
}
