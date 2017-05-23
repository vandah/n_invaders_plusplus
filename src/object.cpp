#include "object.h"
object::object(int sx, int sy, int px, int py)
    : size({ sx, sy })
    , pos({ px, py })
{
}

object::~object() {}

void moving::move(std::pair<int, int> xy)
{
  // TODO check if not outside of the window
  pos = { pos.first + xy.first, pos.second + xy.second };
}
