#ifndef OBJECT_MOVING_PLAYER
#define OBJECT_MOVING_PLAYER

#include "moving.h"

class player : public moving {
  public:
  player();
  ~player();
  void reset();
};
#endif
