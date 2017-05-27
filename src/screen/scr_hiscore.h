#ifndef SCR_HISCORE
#define SCR_HISCORE

#include "../main.h"
#include "scr_list.h"
#include "screen_base.h"

/// show high scores
class scr_hiscore : public scr_list {
  public:
  scr_hiscore();
  void redraw() const;
  void draw_hiscores() const;
  ~scr_hiscore();

  protected:
  std::vector<std::pair<std::string, int>> hiscores;
};

#endif
