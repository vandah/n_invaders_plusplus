#include "globals.h"

std::vector<std::string> levels = {
  "", "examples/lvl1.txt", "examples/lvl2.txt", "examples/lvl3.txt",
  "examples/lvl4.txt", "examples/lvl5.txt",
};

std::string bunkers_file = "examples/bunkers.txt";

std::string hiscore_file = "data/high_scores.txt";

std::string game_over_file = "examples/game_over.txt";

std::string logo_file = "examples/title.txt";

std::string winner_file = "examples/winner.txt";

bool GameOver = false;

void show_version()
{
  auto lines = load_lines(LOGO_FILE);
  std::cout << "\033[1;33m";
  for (auto line : lines) {
    std::cout << line << std::endl;
  }
  std::cout << " Version number " << VERSION << std::endl;
  std::cout << "\033[0m" << std::endl;
  finish(0);
}

void show_help()
{
  std::cout << "\033[1;33m"
            << "HELP"
            << "\033[0m" << std::endl;

  auto lines = load_lines(HELP_FILE);

  for (auto line : lines) {
    std::cout << line << std::endl;
  }

  finish(0);
}

void get_opts(int argc, char** argv)
{
  for (int i = 0; i < argc; ++i) {
    std::string opt = argv[i];

    if (opt == "--version") {
      show_version();
    } else if (opt == "--help" || opt == "-h") {
      show_help();
    } else if (opt == "--hiscores" || opt == "-s") {
      show_hiscores();
    } else if (opt == "--bunkers" || opt == "-b") {
      show_bunkers();
      finish(0);
    } else if (opt == "--level1" || opt == "-1") {
      if (i + 1 < argc) {
        levels[1] = argv[i + i];
        ++i;
      }
    } else if (opt == "--level2" || opt == "-2") {
      if (i + 1 < argc) {
        levels[2] = argv[i + i];
        ++i;
      }
    } else if (opt == "--level3" || opt == "-3") {
      if (i + 1 < argc) {
        levels[3] = argv[i + i];
        ++i;
      }
    } else if (opt == "--level4" || opt == "-4") {
      if (i + 1 < argc) {
        levels[4] = argv[i + i];
        ++i;
      }
    } else if (opt == "--level5" || opt == "-5") {
      if (i + 1 < argc) {
        levels[5] = argv[i + i];
        ++i;
      }
    } else if (opt == "--bunker-file" || opt == "-bf") {
      if (i + 1 < argc) {
        bunkers_file = argv[i + 1];
        ++i;
      }
    } else if (opt == "--hiscore-file" || opt == "-hf") {
      if (i + 1 < argc) {
        hiscore_file = argv[i + 1];
        ++i;
      }
    }
  }
}

void show_hiscores()
{
  std::vector<std::pair<std::string, int>> hiscores = get_hiscores();
  int rank = 1;
  for (auto line : hiscores) {
    std::cout << "#" << std::setw(2) << rank << "  " << std::setw(30)
              << line.first << " " << std::setw(20) << line.second << std::endl;
    rank++;
  }
  finish(0);
}

void show_bunkers()
{
  std::vector<std::vector<int>> bunker = get_bunkers();
  for (auto x : bunker) {
    for (auto b : x) {
      std::cout << b;
    }
    std::cout << std::endl;
  }
}

std::vector<std::pair<std::string, int>> get_hiscores()
{
  std::vector<std::pair<std::string, int>> hiscores;
  std::string name;
  int score;

  std::ifstream input(HISCORE_FILE, std::ios::in);

  if (input.bad()) {
    finish(ERROR_CORRUPTED_FILE);
  }

  if (!input.fail()) {
    while (input >> name >> score) {
      hiscores.push_back({ name, score });
    }
    if (input.bad()) {
      finish(ERROR_CORRUPTED_FILE);
    }
  }

  while (hiscores.size() < 10) {
    hiscores.push_back({ "#####", 0 });
  }

  std::sort(hiscores.begin(), hiscores.end(),
      [](const std::pair<std::string, int>& a,
          const std::pair<std::string, int>& b) {
        return a.second > b.second;
      });

  input.close();

  return hiscores;
}

std::vector<std::vector<int>> get_bunkers() { return get_data(BUNKERS_FILE); }

std::vector<std::vector<int>> get_data(std::string file)
{
  std::ifstream input(file, std::ios::in);
  int num;
  char c;
  int i = 0;

  std::vector<int> line;
  std::vector<std::vector<int>> arr;

  input >> std::noskipws;

  if (input.bad()) {
    finish(ERROR_CORRUPTED_FILE);
  }

  while (!input.fail()) {
    input >> num >> c;

    line.push_back(num);

    if (input.bad()) {
      finish(ERROR_CORRUPTED_FILE);
    }

    if (!input.eof() && c == '\n') {
      arr.push_back(line);
      line.clear();
      i++;
    }
  }

  input.close();

  return arr;
}

std::vector<std::string> load_lines(std::string file)
{
  std::ifstream input(file, std::ios::in);
  std::string line;
  char c;
  input >> std::noskipws;

  if (input.bad()) {
    finish(ERROR_CORRUPTED_FILE);
  }

  std::vector<std::string> lines;
  while (!input.eof()) {
    line = "";
    while (input >> c) {
      if (input.bad()) {
        finish(ERROR_CORRUPTED_FILE);
      }

      if (c == '\n') {
        break;
      }
      line += c;
    }

    lines.push_back(line);
  }

  if (lines.empty()) {
    finish(ERROR_EMPTY_FILE);
  }

  input.close();

  return lines;
}

void finish(int exit_code)
{
  switch (exit_code) {
  case ERROR_SMALL_SCREEN:
    std::cout << ""
              << "\033[0;31m"
              << "ERROR: "
              << "\033[0m"
              << "SCREEN TOO SMALL" << std::endl;
    break;

  case ERROR_EMPTY_FILE:
    std::cout << ""
              << "\033[0;31m"
              << "ERROR: "
              << "\033[0m"
              << "THE FILE IS EMPTY" << std::endl;
    break;

  case ERROR_CORRUPTED_FILE:
    std::cout << ""
              << "\033[0;31m"
              << "ERROR: "
              << "\033[0m"
              << "FILE IS CORRUPTED OR NOT ACCESSIBLE" << std::endl;
    break;
  default:
    break;
  }
  exit(exit_code);
}
