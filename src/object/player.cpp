#include "player.h"

player::player()
    : active_missile(NULL)
    , lives(DEFAULT_LIVES)
    , score(0)
{
  pos = { size.first - 5, size.second / 2 - 2 };
  old_pos = pos;
}

player::~player()
{
  if (active_missile) {
    active_missile->destroy();
    delete active_missile;
  }
  Player = NULL;
}

void player::move_right()
{
  move({ 0, 1 });
  redraw();
}

void player::move_left()
{
  move({ 0, -1 });
  redraw();
}

void player::shoot()
{
  if (!active_missile) {
    active_missile = new missile();
    active_missile->set_pos({ pos.first - 1, pos.second + 2 });
    move({ 0, 0 });
    redraw();
  }
}

void player::die()
{
  reset();
  lives--;
}

bool player::is_dead() { return (lives <= 0); }

void player::reset()
{
  /// reset position
  pos = { size.first - 5, size.second / 2 - 2 };

  move({ 0, 0 });

  redraw();

  /// delete missile
  if (active_missile) {
    active_missile->destroy();
    delete active_missile;
  }
}

std::vector<std::string> player::get_looks() const
{
  if (active_missile) {
    return std::vector<std::string>{ "/___\\" };
  } else {
    return std::vector<std::string>{ "/_^_\\" };
  }
}

/// color yellow
int player::color() const { return 6; }

player::missile::missile()
    : crash(false)
{
  down = false;
}

std::vector<std::string> player::missile::get_looks() const
{
  return std::vector<std::string>{ "!", " " };
}

int player::missile::color() const { return 5; }

player::missile::~missile()
{
  if (Player) {
    Player->active_missile = NULL;
  }
}
