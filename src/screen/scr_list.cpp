#include "scr_list.h"

scr_list::scr_list()
    : items(std::vector<std::pair<std::string, int>>{
          { "Go back", SCREEN_MENU }, { "Or also back", SCREEN_MENU } })
    , selected_idx(0)
    , back(SCREEN_MENU)
    , screen_title("")
{
  win = newwin(rows - 1, cols - 1, 1, 1);
  keypad(win, TRUE);
  midcol = cols / 2;
  midrow = rows / 2;
  max_row = rows / 2 - 13;
}

scr_list::~scr_list() {}

void scr_list::draw_title() const
{
  auto lines = load_lines("examples/title.txt");

  attron(COLOR_PAIR(6));
  int i = max_row - lines.size() - 3;
  for (std::string line : lines) {
    mvprintw(i, cols / 2 - line.length() / 2 + 4, line.c_str());
    ++i;
  }
  attroff(A_BOLD);

  attron(COLOR_PAIR(3) | A_BOLD);
  mvprintw(max_row, cols / 2 - screen_title.length() / 2, screen_title.c_str());
  attroff(A_BOLD);
}

void scr_list::draw_list() const
{
  draw_title();
  int current_row = midrow - items.size() / 2;
  for (unsigned int i = 0; i < items.size(); ++i) {
    attron(COLOR_PAIR(1 + (i == selected_idx)));

    mvprintw(current_row, midcol - (items[i].first.length() / 2), " %s ",
        items[i].first.c_str());

    current_row += 2;
  }
}

void scr_list::key_enter() { switch_screen(items[selected_idx].second); }

void scr_list::key_up()
{
  if (items.size()) {
    selected_idx = items.size() - 1 + selected_idx;
    selected_idx %= items.size();
  }
}

void scr_list::key_down()
{
  if (items.size()) {
    selected_idx++;
    selected_idx %= items.size();
  }
}

void scr_list::key_backspace() { switch_screen(back); }

void scr_list::key_right() { key_enter(); }

void scr_list::key_left() { key_backspace(); }

void scr_list::redraw() const
{
  scr_clear();
  draw_list();
  refresh();
}
