#include "scr_hiscore.h"

scr_hiscore::scr_hiscore()
    : scr_list()
{
  screen_title = "HIGH SCORES";
  midrow += 12;
  hiscores = get_hiscores();
}

void scr_hiscore::redraw() const
{
  scr_clear();
  draw_hiscores();
  draw_list();
  refresh();
}

void scr_hiscore::draw_hiscores() const
{
  int width = gui.cols / 2;
  int name_width = 3 * (width - 2) / 5;
  int score_width = 2 * (width - 2) / 5;
  int curr_row = gui.rows / 2 - 10;

  std::pair<std::string, int> line;
  std::stringstream ss;

  attron(COLOR_PAIR(1));

  for (int rank = 1; rank <= 10; ++rank) {
    if (rank <= hiscores.size()) {
      line = hiscores[rank - 1];
    } else {
      line = { "#####", 0 };
    }

    if (rank <= 3) {
      attron(COLOR_PAIR(1) | A_BOLD);
    }

    ss << "#" << std::setw(2) << rank << "  " << std::setw(name_width)
       << line.first << " " << std::setw(score_width) << line.second;
    mvprintw(curr_row, midcol - ss.str().size() / 2, "%s", ss.str().c_str());
    ss.str("");
    attroff(A_BOLD);
    curr_row += 2;
  }
}

scr_hiscore::~scr_hiscore() {}
