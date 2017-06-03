#include "game.h"
#include "bunker.h"
#include "invader.h"
#include "player.h"

game::game()
    : is_paused(false)
{
  level = 1;

  score = 0;

  lives = DEFAULT_LIVES;

  Player = new player();

  battlefield.clear();
  battlefield.resize(size.first, std::vector<object*>(size.second, NULL));

  load_bunkers();

  for (unsigned int i = 0; i < Bunkers.size(); ++i) {
    for (unsigned int j = 0; j < Bunkers[i].size(); ++j) {
      if (Bunkers[i][j]) {
        Bunkers[i][j]->redraw();
      }
    }
  }

  load_invaders();

  for (unsigned int i = 0; i < Invaders.size(); ++i) {
    for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
      if (Invaders[i][j]) {
        Invaders[i][j]->redraw();
      }
    }
  }
}

game::~game()
{
  for (unsigned int i = 0; i < battlefield.size(); ++i) {
    for (unsigned int j = 0; j < battlefield[i].size(); ++j) {
      if (battlefield[i][j]) {
        battlefield[i][j]->destroy();
        delete battlefield[i][j];
      }
    }
  }

  battlefield.clear();

  Bunkers.clear();

  Invaders.clear();
}

void game::reset() {}

void game::redraw() const
{
  Player->redraw();

  if (Player->active_missile) {
    Player->active_missile->fall();
    if (Player->active_missile) {
      Player->active_missile->redraw();

      if (Player->active_missile->top()) {
        Player->active_missile->destroy();
        delete Player->active_missile;
      }
    }
  }

  for (unsigned int i = 0; i < Invaders.size(); ++i) {
    for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
      if (Invaders[i][j]) {
        Invaders[i][j]->redraw();
      }
    }
  }

  print_status_line();
}

void game::print_status_line() const
{
  std::stringstream line;
  line.str("");

  line << "LEVEL: " << level << "  SCORE: " << score;

  mvprintw(size.first - 3, size.second / 2 - line.str().length() / 2,
      line.str().c_str());
}

void game::toggle_pause() { is_paused = !is_paused; }

void game::game_over() {}

void game::move_right()
{
  if (!is_paused) {
    Player->move_right();
  }
}

void game::move_left()
{
  if (!is_paused) {
    Player->move_left();
  }
}

void game::shoot()
{
  if (!is_paused) {
    Player->shoot();
  }
}

int game::color() const { return 1; }

std::vector<std::string> game::get_looks() const
{
  return std::vector<std::string>{};
}

void game::load_bunkers()
{
  std::vector<std::vector<int>> one_bunker = get_bunkers();

  // void scr_game::bunkers::load()
  //{
  //  std::vector<std::vector<int>> bunker = get_bunkers();
  //  int space = 3;
  //  int bunker_width = bunker[0].size() * 2 + space;
  //  int cnt = (cols - 6) / bunker_width;
  //
  //  pos.first = ((cols - 2) - (bunker_width * cnt));
  //  pos.second = rows - bunker_width;
  //
  //  std::vector<std::vector<int>> bunker_array;
  //  for (int i = 0; i < cnt; ++i) {
  //    for (unsigned int j = 0; j < bunker.size(); ++j) {
  //      for (unsigned int k = 0; k < bunker[j].size(); ++k) {
  //        attron(COLOR_PAIR(3));
  //        mvprintw(pos.second + j, i * (bunker_width) + pos.first + k,
  //            bunker[j][k] ? "#" : "");
  //      }
  //    }
  //  }
  //}
}

void game::load_invaders() {}
