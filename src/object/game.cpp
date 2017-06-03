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

  int space = 3;
  int bunker_width = one_bunker[0].size() * 2 + space;
  int cnt = (size.second - 6) / bunker_width;

  Bunkers.init_arr(one_bunker.size(), size.second);

  Bunkers.pos = { size.first - bunker_width,
    ((size.second - 2) - (bunker_width * cnt)) };

  for (int i = 0; i < cnt; ++i) {
    for (unsigned int j = 0; j < one_bunker.size(); ++j) {
      for (unsigned int k = 0; k < one_bunker[j].size(); ++k) {
        if (one_bunker[j][k]) {
          bunker* b = new bunker();
          b->pos = { j + Bunkers.pos.first,
            i * (bunker_width) + k + Bunkers.pos.second };

          battlefield[b->pos.first][b->pos.second] = b;

          Bunkers[b->pos.first - Bunkers.pos.first]
                 [b->pos.second - Bunkers.pos.second]
              = b;

          Bunkers.cnt++;
        }
      }
    }
  }
}

void game::load_invaders()
{
  std::vector<std::vector<int>> int_invaders = get_data(LVL_FILE(level));

  Invaders.init_arr(10 + int_invaders.size() * 2, size.second);

  Invaders.pos = { 4, 4 };

  std::pair<int, int> tmp_pos = Invaders.pos;

  for (unsigned int i = 0; i < int_invaders.size(); ++i) {
    for (unsigned int j = 0; j < int_invaders[i].size(); ++j) {
      if (int_invaders[i][j]) {
        invader* I = new invader(int_invaders[i][j]);
        I->pos = tmp_pos;

        for (unsigned int k = 0; k < I->current_look().size(); ++k) {
          Invaders[I->pos.first - Invaders.pos.first]
                  [I->pos.second - Invaders.pos.second + k]
              = I;
          battlefield[I->pos.first][I->pos.second + k] = I;
          tmp_pos.second++;
        }

        tmp_pos.second++;
      }
    }
    tmp_pos.first += 2;
    tmp_pos.second = 4;
  }
}
