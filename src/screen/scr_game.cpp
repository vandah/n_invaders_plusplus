#include "scr_game.h"

scr_game::scr_game()
    : is_paused(false)
{
  win = newwin(gui.rows - 1, gui.cols - 1, 1, 1);
  keypad(win, TRUE);
}

scr_game::~scr_game() {}

void scr_game::redraw() const
{
  scr_clear();

  if (is_paused) {
    attron(COLOR_PAIR(2));
    for (int i = 2; i < gui.cols - 1; ++i) {
      mvprintw(gui.rows / 2, i, "-");
    }
    mvprintw(gui.rows / 2, gui.cols / 2 - 4, "> PAUSE <");
  }

  Player.redraw();
  wmove(win, 0, 0);
  refresh();
}

void scr_game::key_right()
{
  if (!is_paused) {
    Player.move_right();
  }
}

void scr_game::key_left()
{
  if (!is_paused) {
    Player.move_left();
  }
}

void scr_game::key_up()
{
  if (!is_paused) {
    Player.shoot();
  }
}

void scr_game::key_pause()
{
  is_paused = !is_paused;
  redraw();
}

void scr_game::key_quit() { gui.switch_screen(SCREEN_MENU); }

void scr_game::key_backspace() { key_quit(); }

void scr_game::check_state()
{
  if (Player.is_dead()) {
    game_over();
  }
}

void scr_game::game_over() {}

void scr_game::handle_timer()
{
  if (!is_paused) {
    redraw();
    Player.handle_timer();
  }

  handle_event(wgetch(win));
}
