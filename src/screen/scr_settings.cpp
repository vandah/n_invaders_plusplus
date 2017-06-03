#include "scr_settings.h"

scr_settings::scr_settings()
    : scr_list()
{
  items.clear();
  for (int i = 1; i <= LVL_CNT; ++i) {
    items.push_back({ "Filename for lvl " + std::to_string(i), SCREEN_UNDEF });
  }
  items.push_back({ "Reset to defaults", SCREEN_UNDEF });
  items.push_back({ "Go back", SCREEN_MENU });
  screen_title = "SETTINGS";
}

scr_settings::~scr_settings() {}
