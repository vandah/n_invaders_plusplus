#include "object.h"
#include "../view.h"

int object::level(1);

int object::score(0);

int object::lives(DEFAULT_LIVES);

std::vector<std::vector<object*>> object::battlefield;

std::pair<int, int> object::size({ gui.rows, gui.cols });

player* object::Player(NULL);

object::grid<invader> object::Invaders;

object::grid<bunker> object::Bunkers;

object::object()
    : pos({ 0, 0 })
    , choice(0)
{
  size = { gui.rows, gui.cols };
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
