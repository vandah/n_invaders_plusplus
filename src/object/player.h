#ifndef OBJECT_MOVING_PLAYER
#define OBJECT_MOVING_PLAYER

#include "moving.h"
#include "missile.h"

class player : public moving {
  public:
  player();
  ~player();

  /// move player's ship right
  void move_right();

  /// move player's ship left
  void move_left();

  /// if it is possible, shoot a missile
  void shoot();

  /// reset player to initial position
  void reset();

  /// what to do if player was shot
  void die();

  protected:
  missile* active_missile;
};
#endif
