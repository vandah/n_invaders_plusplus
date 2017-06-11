#include "bunker.h"

bunker::bunker() {}

void bunker::destroy()
{
  next_look();
  redraw();

  length = 1;

  for (unsigned int i = 0; i < current_look().size(); ++i) {
    Bunkers[pos.first - Bunkers.pos.first][pos.second - Bunkers.pos.second]
        = NULL;
  }

  object::destroy();
}

bunker::~bunker() {}

std::vector<std::string> bunker::get_looks() const
{
  return std::vector<std::string>{ "#", " " };
}

int bunker::color() const { return 3; }
