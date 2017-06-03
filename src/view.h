/**
 * \file view.h
 * Screen wrapper, used for basic GUI manipulation.
 */

#ifndef VIEW
#define VIEW

#include "globals.h"

class screen_base;

/// GUI basics
class view {
  public:
  view();
  ~view();

  void init();

  /// top bar indicating game status
  void status_bar(int lvl, int score, int lives);

  /// switch to another screen
  void switch_screen(int s);

  /// receives time tick and alerts the appropriate screen
  void handle_timer();

  /// screen dimensions - x
  int cols;

  /// screen dimensions - y
  int rows;

  protected:
  /// main window
  WINDOW* scr_main;

  /// pointer to the current screen - to enable switching
  screen_base* current_screen;
};
#endif
