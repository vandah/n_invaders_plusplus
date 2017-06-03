#include "object.h"
object::object(int size_x, int size_y, int pos_x, int pos_y)
    : pos({ pos_x, pos_y })
    , choice(0)
    , size({ size_x, size_y })
{
}

std::string object::current_look() const
{
  std::vector<std::string> wardrobe = get_looks();
  if (!wardrobe.empty()) {
    return wardrobe[choice];
  } else {
    return "";
  }
}

void object::next_look()
{
  choice++;
  std::vector<std::string> wardrobe = get_looks();
  choice %= wardrobe.size();
}

void object::reset() { choice = 0; }

void object::destroy()
{
  for (unsigned int i = 0; i < current_look().length(); ++i) {
    battlefield[pos.first][pos.second + i] = NULL;
  }
}

void object::redraw() const
{
  attron(COLOR_PAIR(color()));
  mvprintw(pos.first, pos.second, current_look().c_str());
}

object::~object() {}
