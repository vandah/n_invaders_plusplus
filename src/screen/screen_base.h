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

  /// get character from keyboard
  void read_input();

  /// keypress event handler
  virtual void handle_event(int event);

  /// time tick
  virtual void handle_timer();

  void switch_screen(int new_scr) const;

  protected:
  /// react to <up> or k or w being pressed
  virtual void key_up();

  /// react to <down> or j or s being pressed
  virtual void key_down();

  /// react to <left> or h or a being pressed
  virtual void key_left();

  /// react to <right> or l or d being pressed
  virtual void key_right();

  /// react to <CR> being pressed
  virtual void key_enter();

  /// react to <backspace> being pressed
  virtual void key_backspace();

  /// react to q being pressed
  virtual void key_quit();

  /// react to p being pressed
  virtual void key_pause();

  /// react to <space> being pressed
  virtual void key_space();

  /// the main window
  WINDOW* win;

  /// the middle collumn
  int midcol;

  /// the middle row
  int midrow;

  /// screen size - y
  int rows;

  /// screen size - x
  int cols;
};

#endif
