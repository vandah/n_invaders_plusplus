#ifndef SCR_QUIT
#define SCR_QUIT

#include "screen_base.h"

/// bye bye and quit
class scr_quit : public screen_base {
  public:
  scr_quit();
  ~scr_quit();
  void redraw() const;
  void handle_event(int event);
  void handle_timer();
};

#endif
