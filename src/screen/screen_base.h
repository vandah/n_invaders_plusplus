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

  /// clear screen
  void scr_clear() const;

  /// keypress event handler
  virtual void handle_event(int event);

  virtual void key_up();

  virtual void key_down();

  virtual void key_left();

  virtual void key_right();

  virtual void key_enter();

  virtual void key_backspace();

  virtual void key_quit();

  virtual void key_pause();

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
