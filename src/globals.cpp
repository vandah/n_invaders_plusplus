#include "globals.h"
#include "main.h"

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
