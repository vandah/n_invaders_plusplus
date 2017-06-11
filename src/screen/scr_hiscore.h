#ifndef SCR_HISCORE
#define SCR_HISCORE

#include "scr_list.h"

/// show high scores
class scr_hiscore : public scr_list {
  public:
  /// default constructor + get high scores
  scr_hiscore();

  /// draw the screen again
  void redraw() const;

  /// print high scores
  void draw_hiscores() const;

  /// default destructor
  ~scr_hiscore();

  protected:
  /// array of highest scores and names
  std::vector<std::pair<std::string, int>> hiscores;
};

#endif
