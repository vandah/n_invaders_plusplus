#include "moving.h"

moving::moving()
    : old_pos({ 0, 0 })
{
}

moving::~moving() {}

void moving::move(std::pair<int, int> xy)
{
  int new_x = pos.first + xy.first;
  int new_y = pos.second + xy.second;
  if (new_x > 2 && (unsigned)new_x < gui.cols - current_look().size() - 1 && new_y > 2 && new_y < gui.rows - 1) {
    old_pos = { pos.first, pos.second };
    pos = { new_x, new_y };
  }
}

bool moving::bottom() { return pos.second >= gui.rows - 1; }

bool moving::top() { return pos.second <= 3; }

bool moving::right() { return (unsigned)pos.first >= gui.cols - current_look().size() - 1; }

bool moving::left() { return pos.first <= 2; }

void moving::redraw() const
{
  attron(COLOR_PAIR(1) | A_INVIS);

  for (unsigned int i = 0; i < current_look().size(); ++i) {
    mvprintw(old_pos.second, old_pos.first + i, " ");
  }

  attroff(A_INVIS);

  object::redraw();
}
