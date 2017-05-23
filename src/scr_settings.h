#ifndef SCR_SETTINGS
#define SCR_SETTINGS

#include "scr.h"
#include "scr_list.h"

/// game settings
class scr_settings : public scr_list {
  public:
  scr_settings();
  ~scr_settings();
  void redraw() const;
  void handle_event(int event);
};

#endif
