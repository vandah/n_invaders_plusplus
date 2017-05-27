#include "scr_game.h"

scr_game::scr_game()
    : is_paused(false)
{
  win = newwin(gui.rows - 1, gui.cols - 1, 1, 1);
  keypad(win, TRUE);
}

scr_game::~scr_game() {}

void scr_game::redraw() const { scr_clear(); }

void scr_game::key_right() { Player.move_right(); }

void scr_game::key_left() { Player.move_left(); }

void scr_game::key_up() { Player.shoot(); }

void scr_game::key_pause() {}

void scr_game::key_backspace() {}
