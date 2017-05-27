#include "object.h"
object::object(int size_x, int size_y, int pos_x, int pos_y)
    : size({ size_x, size_y })
    , pos({ pos_x, pos_y })
{
}

object::TLook::TLook() {}

object::TLook::~TLook() {}

std::string object::TLook::current_look()
{
  return (wardrobe.empty()) ? "" : wardrobe[choice];
}

void object::TLook::next_look()
{
  choice++;
  choice %= wardrobe.size();
}

void object::TLook::reset() { choice = 0; }

void object::redraw() {}

void object::destroy() {}

object::~object() {}
