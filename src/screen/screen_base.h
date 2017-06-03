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

  void read_input();

  /// keypress event handler
  virtual void handle_event(int event);

  /// time tick
  virtual void handle_timer();

  void switch_screen(int new_scr);

  protected:
  virtual void key_up();

  virtual void key_down();

  virtual void key_left();

  virtual void key_right();

  virtual void key_enter();

  virtual void key_backspace();

  virtual void key_quit();

  virtual void key_pause();

  virtual void key_space();

  /// the main window
  WINDOW* win;

  int midcol;

  int midrow;

  int rows;

  int cols;
};

#endif
