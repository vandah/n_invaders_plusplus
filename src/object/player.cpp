#include "player.h"
player::player()
    : missile_loaded(true)
{
  reset();
}

player::~player() {}

void player::move_right() { move({ 1, 0 }); }

void player::move_left() { move({ -1, 0 }); }

void player::shoot()
{
  if (!active_missile)
  // TODO create a missile
}

void player::reset() { pos = { gui.cols / 2, gui.rows / 2 }; }
