#ifndef OBJECT_MOVING_PLAYER
#define OBJECT_MOVING_PLAYER

#include "moving.h"

class player : public moving {
  public:
  void redraw();
  void destroy();
  void reset();
};
#endif
