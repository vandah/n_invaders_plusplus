#ifndef SCR
#define SCR

#include "../globals.h"

class scr {
  public:
  /// variable inicialization
  scr();

  /// destructor
  virtual ~scr();

  /// updates the window
  virtual void redraw() const = 0;

  /// keypress event handler
  virtual void handle_event(int event) = 0;

  /// time tick
  virtual void handle_timer() = 0;

  protected:
  /// screens are moving between several states
  int state;

  /// the main window
  WINDOW* win;

  int midcol;

  int midrow;
};

#endif
