#include "invader.h"

invader::invader(int type)
    : type(type)
{
  length = 3;

  if(type==UFO){
    length = 5;
  }
}

void invader::redraw() const
{
  attron(COLOR_PAIR(1) | A_INVIS);

  for (unsigned int i = 0; i < current_look().size(); ++i) {
    mvprintw(Invaders.old_pos.first + pos.first,
        Invaders.old_pos.second + pos.second + i, " ");
  }

  attroff(A_INVIS);

  attron(COLOR_PAIR(color()));

  mvprintw(Invaders.pos.first + pos.first, Invaders.pos.second + pos.second,
      current_look().c_str());
}

void invader::destroy()
{
  for (unsigned int i = 0; i < current_look().size(); ++i) {
    Invaders[pos.first][pos.second + i] = NULL;

    mvprintw(pos.first + Invaders.old_pos.first,
        pos.second + Invaders.old_pos.second + i, " ");

    mvprintw(pos.first + Invaders.pos.first,
        pos.second + Invaders.pos.second + i, " ");

    battlefield[pos.first + Invaders.pos.first]
               [pos.second + Invaders.pos.second + i]
        = NULL;
  }

  // TODO: BONUS

  // if game.is_running(){ //FIXME
  score += points();
  // }
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

std::vector<std::string> invader::missile::get_looks() const
{
  return std::vector<std::string>{ ":", " " };
}

int invader::missile::color() const { return 3; }

void invader::missile::destroy()
{
  for (unsigned int i = 0; i < current_look().size(); ++i) {
    mvprintw(old_pos.first, old_pos.second + i, " ");

    battlefield[pos.first][pos.second + i] = NULL;

    mvprintw(pos.first, pos.second + i, " ");
  }
  Invaders.missiles[init_pos.first][init_pos.second] = NULL;
}

invader::missile::~missile() {}

int invader::points() const
{
  switch (type) {
  case INVADER_1:
    return 150;

  case INVADER_2:
    return 200;

  case INVADER_3:
    return 400;

  case INVADER_4:
    return 1000;

  case UFO:
    return 1500;
  }
  return 0;
}

void invader::shoot()
{
  missile* m = new missile();

  m->pos = { pos.first + Invaders.pos.first + 1,
    pos.second + Invaders.pos.second + 1 };

  m->init_pos = pos;

  Invaders.missiles[pos.first][pos.second] = m;

  m->redraw();
}
