#include "scr_menu.h"

scr_menu::scr_menu()
    : scr_list()
{
  items = std::vector<std::pair<std::string, int>>{ { "Play", SCREEN_GAME },
    { "High Scores", SCREEN_HISCORE }, { "Instructions", SCREEN_INSTRUCTIONS },
    { "Quit", SCREEN_QUIT } };

  back = SCREEN_UNDEF;

  screen_title = "MAIN MENU";

  max_row = rows / 2 - items.size() - 2;
}

scr_menu::~scr_menu() {}
