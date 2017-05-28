#ifndef OBJECT_MOVING_PLAYER
#define OBJECT_MOVING_PLAYER

#include "falling.h"
#include "shooting.h"

#define DEFAULT_LIVES 5

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

  void redraw() const;

//  class missile : falling {
//public:
//    missile();
//    ~missile();
//    void redraw() const;
//
//protected:
//    std::vector<std::string> get_looks() const;
//    int color() const;
//  };

  protected:
  std::vector<std::string> get_looks() const;

  int color() const;

  /// a missile shot by player
  missile* active_missile;

  /// remaining lives
  int lives;

  /// gained score
  int score;
};
#endif
