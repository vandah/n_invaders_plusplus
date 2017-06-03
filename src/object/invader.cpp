#include "invader.h"

invader::invader(int type)
    : type(type)
{
  missiles.push_back(new missile());
}

void invader::destroy()
{
  for (unsigned int i = 0; i < current_look().size(); ++i) {
    Invaders[pos.first - Invaders.pos.first]
            [pos.second - Invaders.pos.second + i]
        = NULL;
    mvprintw(pos.first, pos.second + i, " ");
  }

  // TODO: BONUS

  // if game.is_running(){ //FIXME
  score += points();
  // }

  object::destroy();
}

invader::~invader() {}

void invader::reset() {}

std::vector<std::string> invader::get_looks() const
{
  switch (type) {
  case INVADER_1:
    return std::vector<std::string>{ "/~\\", "/.\\", "\\~/", "\\./" };

  case INVADER_2:
    return std::vector<std::string>{ ">O<", "<o>", "_o-", "-o_" };

  case INVADER_3:
    return std::vector<std::string>{ "@-@", "<+>", "#-#", "%^%" };

  case INVADER_4:
    return std::vector<std::string>{ "<^>", "/^\\", "/|\\", "<|>" };

  case UFO:
    return std::vector<std::string>{ "< oo>", "<o o>", "<oo >", "<ooo>" };
  }
  return std::vector<std::string>{};
}

int invader::color() const
{
  switch (type) {
  case INVADER_1:
    return 1;

  case INVADER_2:
    return 7;

  case INVADER_3:
    return 5;

  case INVADER_4:
    return 6;

  case UFO:
    return 3;
  }
  return 4;
}

invader::missile::missile() { down = true; }

invader::missile::~missile() {}

std::vector<std::string> invader::missile::get_looks() const
{
  return std::vector<std::string>{ ":" };
}

int invader::missile::color() const { return 4; }
