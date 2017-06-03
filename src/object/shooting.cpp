#include "shooting.h"

void shooting::reset() {}

void shooting::missile_base::set_pos(std::pair<int, int> new_pos)
{
  old_pos = pos;
  pos = new_pos;
}

shooting::missile_base::~missile_base() {}

void shooting::missile_base::destroy()
{
  next_look();
  redraw();

  object::destroy();
}
