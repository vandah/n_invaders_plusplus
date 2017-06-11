#ifndef OBJECT_MOVING_SHOOTING_PLAYER
#define OBJECT_MOVING_SHOOTING_PLAYER

#include "shooting.h"

class player : public shooting {
  public:
  /// default constructor
  player();

  /// default destructor
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
    /// default constructor
    missile();

    /// default destructor
    ~missile();

protected:
    /// get available looks
    std::vector<std::string> get_looks() const;

    /// get missiles's color
    int color() const;
  };

  /// a missile shot by player
  missile* active_missile;

  protected:
  /// get available looks
  std::vector<std::string> get_looks() const;

  /// get object's color
  int color() const;

  /// gained score
  int score;
};
#endif
