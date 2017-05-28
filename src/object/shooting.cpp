#include "shooting.h"

void shooting::reset() {}

void shooting::missile::set_pos(std::pair<int, int> new_pos)
{
  pos = new_pos;
  old_pos = { pos.first, pos.second };
}
