#include "missile.h"

missile::missile(bool invader)
    : falling(invader)
{
}

int missile::color() const { return 5; }

std::vector<std::string> missile::get_looks() const
{
  return std::vector<std::string>{ "|", "!" };
}

missile::~missile() {}
