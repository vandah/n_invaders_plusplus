#include "moving.h"

void moving::move(std::pair<int, int> xy)
{
  int new_x = pos.first + xy.first;
  int new_y = pos.second + xy.second;
 if (new_x > 0 && new_x < gui.cols && new_y > 0 && new_y < gui.rows) {
  pos = { new_x, new_y };
  }
}
