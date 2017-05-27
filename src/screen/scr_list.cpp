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
  scr_clear();

  int current_row = midrow - items.size() / 2;
  for (unsigned int i = 0; i < items.size(); ++i) {
    attron(COLOR_PAIR(1 + (i == selected_idx)));

    mvprintw(current_row, midcol - (items[i].first.length() / 2), " %s ",
        items[i].first.c_str());

    current_row += 2;
  }
}

void scr_list::key_enter() { gui.switch_screen(items[selected_idx].second); }

void scr_list::key_up()
{
  if (items.size()) {
    selected_idx--;
    selected_idx %= items.size();
  }
}

void scr_list::key_down()
{
  selected_idx++;
  selected_idx %= items.size();
}

void scr_list::key_backspace() { gui.switch_screen(back); }

void scr_list::key_right() { key_enter(); }

void scr_list::key_left() { key_backspace(); }

void scr_list::redraw() const
{
  draw_list();
  refresh();
}
