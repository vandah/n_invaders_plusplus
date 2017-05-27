#ifndef SCR_GAME
#define SCR_GAME
#include "screen_base.h"
/// game screen
class scr_game : public screen_base {
  public:
  /// constructor
  scr_game();

  /// destructor
  ~scr_game();

  /// draw the whole screen
  void redraw() const;

  /// react on keypress
  void handle_event(int event);
};
#endif
