#ifndef OBJECT_MOVING_SHOOTING_PLAYER
#define OBJECT_MOVING_SHOOTING_PLAYER

#include "shooting.h"

class player : public shooting {
  public:
  player();
  ~player();

  /// move player's ship right
  void move_right();

  /// move player's ship left
  void move_left();

  /// if it is possible, shoot a missile
  void shoot();

  /// missile hit target or screen edge -> remove it
  void clear_missile();

  /// reset player to initial position
  void reset();

  /// what to do if player was shot
  void die();

  /// check number of lives
  bool is_dead();

  class missile : public missile_base {
public:
    missile();
    ~missile();

protected:
    std::vector<std::string> get_looks() const;
    int color() const;
    bool crash;
  };

  /// a missile shot by player
  missile* active_missile;

  protected:
  std::vector<std::string> get_looks() const;

  int color() const;

  /// gained score
  int score;
};
#endif
