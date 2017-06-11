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

void game::reset() {}

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

    if (Invaders.counter % 4 == 0) {
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

    for (unsigned int i = 0; i < Invaders.size(); ++i) {
      for (unsigned int j = 0; j < Invaders[i].size(); ++j) {
        if (Invaders.missiles[i][j] && Invaders.counter % 2) {
          Invaders.missiles[i][j]->fall();
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
          invader* tmp = Invaders[i][j];
          if (!Invaders.missiles[tmp->pos.first][tmp->pos.second]) {
            I = tmp;
          }
        }
      }
    }

    if (I && Invaders.counter % 50 == 0) {
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
    nodelay(stdscr, FALSE);

    char c[2];
    c[1] = '\0';
    int n;
    int esc = 0;
    noecho();

    while (1) {
      n = wgetch(w);
      if (n == '\n') {
        delwin(w);
        nodelay(stdscr, TRUE);
        break;
      } else if (n == 27) {
        esc = 1;
      } else if (esc == 1 && n == 91) {
        esc = 2;
      } else if (esc == 2) {
        esc = 0;
      } else if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z')) {
        esc = 0;
        line += n;
        c[0] = n;
        wprintw(w, c);
      } else if (n == 8 || n == 127 || n == KEY_BACKSPACE) {
        if (!line.empty()) {
          wmove(w, 0, line.length() - 1);
          wprintw(w, " ");
          line.pop_back();
          wmove(w, 0, line.length());
        }
      }
    }

    delwin(w);
    w = NULL;

    int rank = 0;

    for (int i = 0; i < 9 && i < (int)hiscores.size(); ++i) {
      if (score > hiscores[i].second) {
        rank = i;
        break;
      }
    }

    hiscores.insert(rank + hiscores.begin(), { line, score });

    std::ofstream output(HISCORE_FILE, std::ios::out);
    for (int i = 0; i < 10; ++i) {
      output << hiscores[i].first << " " << hiscores[i].second << std::endl;
    }

    output.close();
  }
}

void game::move_right()
{
  if (is_running()) {
    Player->move_right();
  }
}

void game::move_left()
{
  if (is_running()) {
    Player->move_left();
  }
}

void game::shoot()
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
