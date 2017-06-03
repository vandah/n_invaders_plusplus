#include "scr_hiscore.h"

scr_hiscore::scr_hiscore()
    : scr_list()
{
  screen_title = "HIGH SCORES";
  midrow += 12;

  /// load hiscores from file
  hiscores = get_hiscores();
}

void scr_hiscore::redraw() const
{
  scr_clear();

  /// print the top 10 players
  draw_hiscores();

  /// draw the option to go back to menu
  draw_list();

  /// refresh the window to show the changes
  refresh();
}

void scr_hiscore::draw_hiscores() const
{
  /// calculate the total available width
  int width = cols / 2;

  /// set name width to 60% of total width
  int name_width = 3 * (width - 2) / 5;

  /// set space available for prining score to 40% of total width
  int score_width = 2 * (width - 2) / 5;

  /// set current row 10 above the middle so the result is centered
  int curr_row = rows / 2 - 10;

  /// to save the line to be printed before sending it to stringstream
  std::pair<std::string, int> line;

  /// stringstream used for concatenating columns and aligning text
  std::stringstream ss;

  /// set green text on black bg
  attron(COLOR_PAIR(1));

  for (unsigned int rank = 1; rank <= 10; ++rank) {
    if (rank <= hiscores.size()) {
      line = hiscores[rank - 1];
    } else {
      /// empty positions
      line = { "#####", 0 };
    }

    /// highlight first 3 positions
    if (rank <= 3) {
      attron(COLOR_PAIR(1) | A_BOLD);
    }

    /// clear the stringstream
    ss.str("");

    /// put the whole line into a stringstream
    ss << "#" << std::setw(2) << rank << "  " << std::setw(name_width)
       << line.first << " " << std::setw(score_width) << line.second;

    /// and print the line
    mvprintw(curr_row, midcol - ss.str().size() / 2, "%s", ss.str().c_str());

    /// turn of the highlighting
    attroff(A_BOLD);

    /// move 2 lines down to leave some space between lines
    curr_row += 2;
  }
}

scr_hiscore::~scr_hiscore() {}
