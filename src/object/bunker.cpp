#include "bunker.h"

bunker::bunker() {}

bunker::~bunker()
{
  next_look();
  redraw();
}

std::vector<std::string> bunker::get_looks() const
{
  return std::vector<std::string>{ "#", " " };
}

int bunker::color() const { return 4; }
