#include "moving.h"

void moving::move(std::pair<int, int> xy)
{
  // TODO check if not outside of the window
  pos = { pos.first + xy.first, pos.second + xy.second };
}
