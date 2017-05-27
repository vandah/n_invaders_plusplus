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

  /// keypress event handler
  void handle_event(int event);

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
