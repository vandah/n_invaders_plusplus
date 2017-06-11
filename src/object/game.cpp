#include "game.h"
#include "bunker.h"
#include "invader.h"
#include "player.h"

game::game()
    : is_paused(false)
{
  level = 1;

  length = 0;

  score = 0;

  lives = DEFAULT_LIVES;

  GameOver = false;

  Player = new player();

  battlefield.clear();
  battlefield.resize(size.first, std::vector<object*>(size.second, NULL));

  Player->reset();

  load_bunkers();

  load_invaders();
}

game::~game()
{
  GameOver = true;

  for (unsigned int i = 0; i < battlefield.size(); ++i) {
    for (unsigned int j = 0; j < battlefield[i].size(); ++j) {
      if (battlefield[i][j]) {
        object* O = battlefield[i][j];
        battlefield[i][j]->destroy();
        delete O;
      }
    }
  }

  battlefield.clear();

  Bunkers.clear();

  Invaders.clear();
}

void game::reset() const
{
  load_invaders();

  Bunkers.clear();

  load_bunkers();
}

void game::redraw() const
{
  if (is_running()) {
    Invaders.counter++;

    Player->redraw();

    if (Player->active_missile && Invaders.counter % 2 == 0) {
      Player->active_missile->fall();
      if (Player->active_missile) {
        Player->active_missile->redraw();

        if (Player->active_missile->top()) {
          Player->active_missile->destroy();
          delete Player->active_missile;
        }
      }
    }

    if (Invaders.counter % 5 == 0) {
      move_invaders();
    }

    for (unsigned int i = 0; i < Invaders.size(); ++i) {
      for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
        if (Invaders[i][j]) {
          Invaders[i][j]->redraw();

          if (!(Invaders.counter % 9)) {
            Invaders[i][j]->next_look();
          }

          j += Invaders[i][j]->current_look().size();
        }
      }
    }

    invader* I = NULL;
    invader* tmp = NULL;

    for (unsigned int i = 0; i < Invaders.size(); ++i) {
      for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
        if (Invaders.missiles[i][j] && Invaders.counter % 2) {
          Invaders.missiles[i][j]->fall();

          if(GameOver){
            return;
          }

          if (Invaders.missiles[i][j]) {
            if (Invaders.missiles[i][j]->bottom()) {
              object* O = Invaders.missiles[i][j];
              Invaders.missiles[i][j]->destroy();
              delete O;
            }

            if (Invaders.missiles[i][j]) {
              Invaders.missiles[i][j]->redraw();
            }
          }
        } else if (Invaders[i][j]) {
          tmp = Invaders[i][j];

          if (!Invaders.missiles[tmp->pos.first][tmp->pos.second]) {
            I = tmp;
          }
        }
      }
    }

    /// if there are still some invaders left
    if (tmp) {
      /// check if the last one had not reached the bottom
      if (tmp->pos.first + Invaders.pos.first >= Player->pos.first) {
        game_over();
      }
      /// if there aro no invaders left, go to the next level
    } else {
      level++;
      if (level <= LVL_CNT) {
        reset();
      } else {
        game_over();
      }
    }

    if (I && Invaders.counter % 100 == 0) {
      I->shoot();
    }
  }

  print_status_line();
}

void game::print_status_line() const
{
  std::stringstream line;
  line.str("");

  line << "LEVEL: " << level << "  SCORE: " << score << "  LIVES: " << lives;

  attron(COLOR_PAIR(1) | A_BOLD);
  mvprintw(size.first - 3, size.second / 2 - line.str().length() / 2,
      line.str().c_str());
  attroff(A_BOLD);
}

void game::toggle_pause()
{
  is_paused = !is_paused;

  if (is_paused) {
    attron(COLOR_PAIR(2));
    for (int i = 2; i < size.second - 1; ++i) {
      mvprintw(size.first - 4, i, "-");
    }
    std::string line = " > PAUSE < ";
    mvprintw(size.first - 4, (size.second - 1) / 2 - line.length() / 2,
        line.c_str());
  } else {
    attron(COLOR_PAIR(1));
    for (int i = 2; i < size.second - 1; ++i) {
      mvprintw(size.first - 4, i, " ");
    }
  }
}

void game::game_over() const
{
  GameOver = true;
  std::ifstream input(GAME_OVER_FILE, std::ios::in);
  char line[100];

  std::vector<char*> arr;

  int i = 10;

  while (input.getline(line, 100)) {
    mvprintw(i, 10, line);
    ++i;
  }

  ++i;

  input.close();

  std::vector<std::pair<std::string, int>> hiscores = get_hiscores();

  refresh();

  nodelay(stdscr, FALSE);

  if (score > hiscores[hiscores.size() - 1].second) {
    attron(COLOR_PAIR(1));
    mvprintw(i, 20, "NEW HISCORE!!");
    attron(COLOR_PAIR(4));
    i += 2;
    std::string msg = "Enter your name: ";
    mvprintw(i, 21, msg.c_str());

    WINDOW* w = newwin(3, 10, i, 21 + msg.length());
    refresh();
    std::string line = "";

    char c[2];
    c[1] = '\0';
    int n;
    int esc = 0;
    noecho();

    bool end = false;

    while (!end) {
      n = wgetch(w);

      switch (n) {
      case '\n':
        delwin(w);
        end = true;
        break;

      case 27: // escape sequence, char #1
        esc = 1;
        break;

      case 91: // escape sequence, char #2
        if (esc == 1) {
          esc = 2;
        }
        break;

      case 8:
      case 127:
      case KEY_BACKSPACE:
        if (!line.empty()) {
          wmove(w, 0, line.length() - 1);
          wprintw(w, " ");
          line.pop_back();
          wmove(w, 0, line.length());
        }
        break;

      default:
        esc = 0;

        if (!((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z')) || esc == 2) {
          break;
        }

        line += n;
        c[0] = n;
        wprintw(w, c);
      }
    }

    delwin(w);
    w = NULL;

    hiscores.push_back({ line, score });

    std::sort(hiscores.begin(), hiscores.end(),
        [](const std::pair<std::string, int>& a,
            const std::pair<std::string, int>& b) {
          return a.second > b.second;
        });

    std::ofstream output(HISCORE_FILE, std::ios::out);
    for (int i = 0; i < 10; ++i) {
      output << hiscores[i].first << " " << hiscores[i].second << std::endl;
    }

    output.close();
  } else {
    WINDOW* w = newwin(2, 2, 4, 4);
    wgetch(w);
    delwin(w);
  }
  nodelay(stdscr, TRUE);
}

void game::move_right() const
{
  if (is_running()) {
    Player->move_right();
  }
}

void game::move_left() const
{
  if (is_running()) {
    Player->move_left();
  }
}

void game::shoot() const
{
  if (is_running()) {
    Player->shoot();
  }
}

int game::color() const { return 1; }

std::vector<std::string> game::get_looks() const
{
  return std::vector<std::string>{};
}

void game::load_bunkers() const
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

  for (unsigned int i = 0; i < Bunkers.size(); ++i) {
    for (unsigned int j = 0; j < Bunkers[i].size(); ++j) {
      if (Bunkers[i][j]) {
        Bunkers[i][j]->redraw();
      }
    }
  }
}

void game::load_invaders() const
{
  std::vector<std::vector<int>> int_invaders = get_data(LVL_FILE(level));

  clear_invaders();

  Invaders.init_arr(int_invaders.size() * 2, int_invaders[0].size() * 4 - 1);

  // offset leveho horniho rohu mrizky
  Invaders.pos = { 4, 4 };

  Invaders.old_pos = Invaders.pos;

  // relativni pozice v poli Invaders
  std::pair<int, int> tmp_pos = { 0, 0 };

  for (unsigned int i = 0; i < int_invaders.size(); ++i) {
    for (unsigned int j = 0; j < int_invaders[i].size(); ++j) {
      if (int_invaders[i][j]) {
        invader* I = new invader(int_invaders[i][j]);
        I->pos = tmp_pos;

        for (unsigned int k = 0; k < I->current_look().size(); ++k) {
          Invaders[I->pos.first][I->pos.second + k] = I;

          battlefield[I->pos.first + Invaders.pos.first]
                     [I->pos.second + Invaders.pos.second + k]
              = I;

          tmp_pos.second++;
        }

        tmp_pos.second++;
      }
    }
    tmp_pos.first += 2;
    tmp_pos.second = 0;
  }

  for (unsigned int i = 0; i < Invaders.size(); ++i) {
    for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
      if (Invaders[i][j]) {
        Invaders[i][j]->redraw();
      }
    }
  }
}

void game::move_invaders() const
{
  Invaders.old_pos = Invaders.pos;

  if (Invaders.pos.first >= Bunkers.pos.first - (int)Invaders.size()
      && !Bunkers.empty()) {
    destroy_bunkers();
  }

  if (Invaders.pos.second <= 4) {
    Invaders.pos.first++;
    Invaders.pos.second++;
    Invaders.right = true;
  } else if ((unsigned)Invaders.pos.second
      >= size.second - 3 - Invaders[0].size()) {
    Invaders.pos.first++;
    Invaders.pos.second--;
    Invaders.right = false;
  } else if (Invaders.right) {
    Invaders.pos.second++;
  } else {
    Invaders.pos.second--;
  }

  for (unsigned int i = 0; i < Invaders.size(); ++i) {
    for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
      if (Invaders[i][j]) {
        int current_size = Invaders[i][j]->current_look().size();

        for (unsigned int k = 0; k < Invaders[i][j]->current_look().size();
             ++k) {
          battlefield[Invaders.old_pos.first + i]
                     [Invaders.old_pos.second + j + k]
              = NULL;
        }

        for (unsigned int k = 0; k < Invaders[i][j]->current_look().size();
             ++k) {
          if (battlefield[Invaders.pos.first + i]
                         [Invaders.pos.second + j + k]) {
            battlefield[Invaders.pos.first + i][Invaders.pos.second + j + k]
                ->destroy();
            delete battlefield[Invaders.pos.first + i]
                              [Invaders.pos.second + j + k];

            invader* I = Invaders[i][j];
            if (I) {
              I->destroy();
              delete I;
            }
            break;
          } else {
            battlefield[Invaders.pos.first + i][Invaders.pos.second + j + k]
                = Invaders[i][j];
          }
        }
        j += current_size;
      }
    }
  }
}

bool game::is_running() const { return (!is_paused && lives > 0); }

void game::destroy_bunkers() const
{
  for (unsigned int i = 0; i < Bunkers.size(); ++i) {
    for (unsigned int j = 0; j < Bunkers[i].size(); ++j) {
      if (Bunkers[i][j]) {
        object* O = Bunkers[i][j];
        Bunkers[i][j]->destroy();
        delete O;
      }
    }
  }

  Bunkers.clear();
}

void game::clear_invaders() const
{
  for (unsigned int i = 0; i < Invaders.size(); ++i) {
    for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
      if (Invaders.missiles[i][j]) {
        object* O = Invaders.missiles[i][j];
        Invaders.missiles[i][j]->destroy();
        delete O;
      }

      if (Invaders[i][j]) {
        object* O = Invaders[i][j];
        Invaders[i][j]->destroy();
        delete O;
      }
    }
  }
}
