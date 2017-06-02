#include "game.h"
#include "bunker.h"
#include "invader.h"
#include "player.h"

game::game()
{
  Player = new player();
  battlefield.clear();
  battlefield.resize(size.first, std::vector<object*>(size.second, NULL));
  load_bunkers();
  load_invaders();
}

game::~game()
{
  delete Player;

  for (auto row : battlefield) {
    for (auto cell : row) {
      if (cell) {
        delete cell;
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
    Player->active_missile->redraw();

    if (Player->active_missile->top()) {
      delete Player->active_missile;
      Player->active_missile = NULL;
    }
  }
}

void game::toggle_pause() { is_paused = !is_paused; }

void game::game_over() {}

void game::move_right() { Player->move_right(); }

void game::move_left() { Player->move_left(); }

void game::shoot() { Player->shoot(); }

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
