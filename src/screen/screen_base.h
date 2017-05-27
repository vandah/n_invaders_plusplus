#ifndef SCREEN_BASE
#define SCREEN_BASE

#include "../globals.h"

class screen_base {
  public:
  /// variable inicialization
  screen_base();

  /// destructor
  virtual ~screen_base();

  /// updates the window
  virtual void redraw() const = 0;

  /// keypress event handler
  virtual void handle_event(int event) = 0;

  /// time tick
  void handle_timer();

  protected:
  /// Screens are moving between several states
  int state;

  /// the main window
  WINDOW* win;

  int midcol;

  int midrow;
};

#endif
