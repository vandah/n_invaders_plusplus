#include "object.h"
object::object(int sx, int sy, int px, int py)
    : size({ sx, sy })
    , pos({ px, py })
{
}

object::~object() {}

