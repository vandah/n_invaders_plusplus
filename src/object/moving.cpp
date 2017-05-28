#include "moving.h"

void moving::move(std::pair<int, int> xy)
{
  int new_x = pos.first + xy.first;
  int new_y = pos.second + xy.second;
  if (new_x > 2 && new_x < gui.cols - current_look().size() - 1 && new_y > 2
      && new_y < gui.rows - 1) {
    pos = { new_x, new_y };
  }
}

bool moving::bottom() { return pos.second >= gui.rows - 1; }

bool moving::top() { return pos.second <= 3; }

bool moving::right()
{
  return pos.first >= gui.cols - current_look().size() - 1;
}

bool moving::left() { return pos.first <= 2; }
