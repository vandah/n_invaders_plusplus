#include "player.h"

player::player()
    : active_missile(NULL)
    , score(0)
{
  pos = { size.first - 5, (size.second - 1) / 2 - 2 };
  old_pos = pos;
  length = 5;
}

player::~player()
{
  die();

  if (!is_dead() && !GameOver) {
    Player = new player();
    Player->active_missile = active_missile;
    Player->reset();
  } else {
    GameOver = true;
    Player = NULL;

    object::destroy();
  }
}

void player::move_right()
{
  move({ 0, 1 });
  if (Player) {
    Player->redraw();
  }
}

void player::move_left()
{
  move({ 0, -1 });
  if (Player) {
    Player->redraw();
  }
}

void player::shoot()
{
  if (!active_missile) {
    active_missile = new missile();
    active_missile->set_pos({ pos.first - 1, pos.second + 2 });
    move({ 0, 0 });
    if (Player) {
      Player->redraw();
    }
  }
}

void player::die() { lives--; }

bool player::is_dead() { return (lives <= 0); }

void player::reset()
{
  for (unsigned int i = 0; i < current_look().size(); ++i) {
    mvprintw(pos.first, pos.second + i, " ");
  }

  /// reset position
  pos = { size.first - 5, (size.second - 1) / 2 - 2 };

  for (unsigned int i = 0; i < current_look().size(); ++i) {
    battlefield[pos.first][pos.second + i] = this;
  }

  if (Player) {
    Player->redraw();
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
