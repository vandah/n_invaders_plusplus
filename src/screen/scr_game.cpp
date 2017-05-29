#include "scr_game.h"

scr_game::scr_game()
    : is_paused(false)
{
  win = newwin(gui.rows - 1, gui.cols - 1, 1, 1);
  keypad(win, TRUE);
  nodelay(win, TRUE);

  battlefield.clear();
  battlefield.resize(gui.rows);

  for (auto v : battlefield) {
    v.resize(gui.cols);
    std::fill(v.begin(), v.end(), 0);
  }

  scr_clear();

  Player = new player();
  Bunkers = new bunkers();
  invaders.push_back(new invader(1));
}

scr_game::~scr_game()
{
  delete Player;
  delete Bunkers;
}

void scr_game::redraw() const
{
  attron(COLOR_PAIR(2));
  if (is_paused) {

    for (int i = 2; i < gui.cols - 1; ++i) {
      mvprintw(gui.rows / 2, i, "-");
    }

    mvprintw(gui.rows / 2, gui.cols / 2 - 4, "> PAUSE <");
  } else {
    Player->redraw();
  }

  wmove(win, 0, 0);
  refresh();
}

void scr_game::check_player_conflicts()
{
  for (unsigned int i = 0; i < Player->current_look().size(); ++i) {
    /// the field is either free or PLAYER's
    if (battlefield[Player->pos.first + i][Player->pos.second] ^ PLAYER) {
      battlefield[Player->pos.first + i][Player->pos.second] = FREE;
    } else {
      Player->die();
    }
  }
}

void scr_game::key_right()
{
  if (!is_paused) {
    for (unsigned int i = 0; i < Player->current_look().size(); ++i) {
      /// the field is either free or player's
      //      if (battlefield[Player->pos.first + i][Player->pos.second] ^
      //      PLAYER)
      //      {
      //        battlefield[Player->pos.first + i][Player->pos.second] = FREE;
      //      }
    }
    Player->move_right();
  }
}

void scr_game::key_left()
{
  if (!is_paused) {
    Player->move_left();
  }
}

void scr_game::key_up()
{
  if (!is_paused) {
    Player->shoot();
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
  if (Player->is_dead()) {
    game_over();
  }
}

void scr_game::game_over() {}

void scr_game::handle_timer()
{
  if (!is_paused) {
    redraw();
    Player->redraw();
    if (Player->active_missile) {
      Player->active_missile->fall();
      Player->active_missile->redraw();

      if (Player->active_missile->top()) {
        delete Player->active_missile;
        Player->active_missile = NULL;
        Player->redraw();
      }
    }
  }
  read_input();
}

scr_game::bunkers::bunkers() { reset(); }

scr_game::bunkers::~bunkers() {}

void scr_game::bunkers::load()
{
  std::vector<std::vector<int>> bunker = get_bunkers();
  int space = 3;
  int bunker_width = bunker[0].size() * 2 + space;
  int cnt = (gui.cols - 6) / bunker_width;

  pos.first = ((gui.cols - 2) - (bunker_width * cnt));
  pos.second = gui.rows - bunker_width;

  std::vector<std::vector<int>> bunker_array;
  for (int i = 0; i < cnt; ++i) {
    for (unsigned int j = 0; j < bunker.size(); ++j) {
      for (unsigned int k = 0; k < bunker[j].size(); ++k) {
        attron(COLOR_PAIR(3));
        mvprintw(pos.second + j, i * (bunker_width) + pos.first + k,
            bunker[j][k] ? "#" : "");
      }
    }
  }
}

void scr_game::bunkers::display() {}

void scr_game::bunkers::reset() { load(); }

std::vector<std::string> scr_game::bunkers::get_looks() const
{
  return std::vector<std::string>{ "" };
}

int scr_game::bunkers::color() const { return 4; }
