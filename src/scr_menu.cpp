#include "scr_menu.h"
#include "main.h"
#include "scr.h"

scr_menu::scr_menu()
    : scr_list()
{
  items = std::vector<std::pair<std::string, int>>{ { "Play", SCREEN_GAME },
    { "High Scores", SCREEN_HISCORE }, { "Settings", SCREEN_SETTINGS },
    { "Quit", SCREEN_QUIT } };
  back = SCREEN_UNDEF;
}

scr_menu::~scr_menu() {}

void scr_menu::redraw() const
{
  draw_list();
  refresh();
}
