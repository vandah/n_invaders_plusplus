#ifndef SCR_HISCORE
#define SCR_HISCORE

#include "scr.h"
#include "scr_list.h"

/// show high scores
class scr_hiscore : public scr_list {
  public:
  scr_hiscore();
  ~scr_hiscore();
  void redraw() const;
  void handle_event(int event);
};

#endif
