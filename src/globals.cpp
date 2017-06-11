#include "globals.h"

bool GameOver = false;

void show_version()
{
  std::cout << "Version number " << VERSION << std::endl;
  finish(0);
}

void show_help()
{
  std::cout << "HELP" << std::endl;
  // TODO write help
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

  if (!input.fail()) {
    while (input >> name >> score) {
      hiscores.push_back({ name, score });
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
  while (!input.fail()) {
    input >> num >> c;

    line.push_back(num);

    if (!input.eof() && c == '\n') {
      arr.push_back(line);
      line.clear();
      i++;
    }
  }

  input.close();

  return arr;
}

void finish(int exit_code) { exit(exit_code); }
