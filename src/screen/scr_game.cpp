#include "scr_game.h"

scr_game::scr_game()
    : is_paused(false)
{
  win = newwin(rows - 1, cols - 1, 1, 1);
  keypad(win, TRUE);
  nodelay(win, TRUE);

  scr_clear();

  Game = new game();
}

scr_game::~scr_game() { delete Game; }

void scr_game::redraw() const
{
  Game->redraw();
  wmove(win, 0, 0);
  refresh();
}

void scr_game::key_right() { Game->move_right(); }

void scr_game::key_left() { Game->move_left(); }

void scr_game::key_up() { Game->shoot(); }

void scr_game::key_space() { key_up(); }

void scr_game::key_pause() { Game->toggle_pause(); }

void scr_game::key_quit() { switch_screen(SCREEN_MENU); }

void scr_game::key_backspace() { key_quit(); }

void scr_game::handle_timer()
{
  redraw();
  read_input();
}
