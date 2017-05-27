#ifndef SCR_GAME
#define SCR_GAME
#include "screen_base.h"
/// game screen
class scr_game : public screen_base {
  public:
  scr_game();
  ~scr_game();
  void redraw() const;
  void handle_event(int event);
  void handle_timer();
};
#endif
