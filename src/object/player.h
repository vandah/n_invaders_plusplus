#ifndef OBJECT_MOVING_PLAYER
#define OBJECT_MOVING_PLAYER

#include "moving.h"

class player : public moving {
  public:
  player();
  ~player();
  void move_right();
  void move_left();
  void shoot();
  void reset();

  protected:
  bool missile_loaded;
};
#endif
