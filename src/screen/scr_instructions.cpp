#include "scr_instructions.h"

scr_instructions::scr_instructions()
    : scr_list()
{
  screen_title = "INSTRUCTIONS";
  midrow += 11;
}

scr_instructions::~scr_instructions() {}

scr_instructions::lines::lines() {}

scr_instructions::lines::lines(std::string title, std::vector<std::string> arr)
    : title(title)
    , content(arr)
{
}

void scr_instructions::redraw() const
{
  scr_clear();

  draw_instructions();

  draw_list();

  refresh();
}

void scr_instructions::draw_instructions() const
{
  int y = rows / 2 - 12;
  auto instructions = get_instructions();
  for (auto l : instructions) {
    y += 3;
    attron(COLOR_PAIR(1) | A_BOLD | A_UNDERLINE);
    mvprintw(y, cols / 2 - l.title.length() / 2, l.title.c_str());
    attroff(A_BOLD | A_UNDERLINE);
    y += 2;

    for (auto m : l.content) {
      mvprintw(y, cols / 2 - 28, m.c_str());
      y += 1;
    }
  }
}

std::vector<scr_instructions::lines> scr_instructions::get_instructions() const
{
  return std::vector<scr_instructions::lines>{
    lines("MENU",
        { "h | LEFT  | BACKSPACE | a             Back",
            "j | DOWN  |           | s             Down",
            "k | UP    |           | w             Up",
            "l | RIGHT | ENTER     | d             Confirm" }),
    lines("GAME",
        { "h | LEFT  |           | a             Move player left",
            "k | UP    | SPACE     | w             Shoot",
            "l | RIGHT |           | d             Move player right",
            "p |       |           |               Pause",
            "q |       | BACKSPACE |               Quit" })
  };
}
