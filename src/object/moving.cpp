#include "moving.h"

moving::moving()
    : old_pos({ 0, 0 })
{
}

moving::~moving() {}

void moving::move(std::pair<int, int> yx)
{
  std::pair<int, int> tmp = { pos.first + yx.first, pos.second + yx.second };

  if (tmp.first > 2 && tmp.first < size.first - 1 && tmp.second > 2
      && (unsigned)tmp.second < size.second - current_look().size() - 1) {
    old_pos = pos;
    pos = tmp;

    for (unsigned int i = 0; i < current_look().size(); ++i) {
      battlefield[old_pos.first][old_pos.second + i] = NULL;
    }

    for (unsigned int i = 0; i < current_look().size(); ++i) {
      if (battlefield[pos.first][pos.second + i]) {
        object* O = battlefield[pos.first][pos.second + i];
        battlefield[pos.first][pos.second + i]->destroy();
        delete O;

        destroy();
        delete this;

        return;
      } else {
        battlefield[pos.first][pos.second + i] = this;
      }
    }
  }
}

bool moving::bottom() { return pos.first >= size.first - 3; }

bool moving::top() { return pos.first <= 3; }

bool moving::right()
{
  return (unsigned)pos.second >= size.second - current_look().size() - 1;
}

bool moving::left() { return pos.second <= 2; }

void moving::redraw() const
{
  attron(COLOR_PAIR(1) | A_INVIS);

  for (unsigned int i = 0; i < current_look().size(); ++i) {
    mvprintw(old_pos.first, old_pos.second + i, " ");
  }

  attroff(A_INVIS);

  object::redraw();
}
