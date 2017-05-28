#include "player.h"

player::player()
    : active_missile(NULL)
    , lives(DEFAULT_LIVES)
    , score(0)
{
  reset();
}

player::~player()
{
  if (active_missile) {
    delete active_missile;
  }
}

void player::move_right() { move({ 1, 0 }); }

void player::move_left() { move({ -1, 0 }); }

void player::shoot()
{
  if (!active_missile) {
    active_missile = new missile();
    active_missile->set_pos(pos);
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
  pos = { gui.cols / 2 - 2, gui.rows - 5 };

  /// delete missile
  if (active_missile) {
    delete active_missile;
    active_missile = NULL;
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
    : falling(false)
{
}

std::vector<std::string> player::missile::get_looks() const
{
  return std::vector<std::string>{ "!" };
}

int player::missile::color() const { return 5; }

player::missile::~missile() {}

void player::redraw() const
{
  if (active_missile) {
    active_missile->redraw();
  }
  object::redraw();
}

void player::handle_timer()
{
  redraw();
  if (active_missile) {
    active_missile->fall();
    if (active_missile->top()) {
      delete active_missile;
      active_missile = NULL;
    }
  }
}
