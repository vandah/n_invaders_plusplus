#ifndef SCR_LIST
#define SCR_LIST
#include "screen_base.h"

/// generic screen for listing items
class scr_list : public screen_base {
  public:
  /// constructor
  scr_list();

  /// destructor
  ~scr_list();

  /// print list items
  void draw_list() const;

  /// updates the window
  void redraw() const;

  /// go to the screen which corresponds to the selection
  void key_enter();

  /// select an element which is higher in the list
  void key_up();

  /// select an element which is lower in the list
  void key_down();

  /// go to the previous screen
  void key_backspace();

  /// implemented as key_enter()
  void key_right();

  /// implemented as key_backspace()
  void key_left();

  protected:
  /// menu items to print (matched with screens they point to)
  std::vector<std::pair<std::string, int>> items;

  /// selected line
  unsigned int selected_idx;
  /// screen to return to if backspace is pressed
  int back;

  std::string screen_title;
};
#endif
