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

scr_game::~scr_game()
{
  delete Game;
  Game = NULL;
}

void scr_game::redraw() const
{
  if (!GameOver) {
    Game->redraw();
    wmove(win, 0, 0);
  } else {
    quit();
  }
  refresh();
}

void scr_game::key_right() { Game->move_right(); }

void scr_game::key_left() { Game->move_left(); }

void scr_game::key_up() { Game->shoot(); }

void scr_game::key_space() { key_up(); }

void scr_game::key_pause() { Game->toggle_pause(); }

void scr_game::key_quit() { quit(); }

void scr_game::key_backspace() { key_quit(); }

void scr_game::handle_timer()
{
  redraw();
  read_input();
}

void scr_game::quit() const
{
  if (win) {
    wmove(win, 40, 50);
  }

  if (Game) {
    Game->game_over();
  }

  switch_screen(SCREEN_MENU);
}
