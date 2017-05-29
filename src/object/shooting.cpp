#include "shooting.h"

void shooting::reset() {}

void shooting::missile_base::set_pos(std::pair<int, int> new_pos)
{
  pos = new_pos;
  old_pos = { pos.first, pos.second };
}

shooting::missile_base::~missile_base() {}
