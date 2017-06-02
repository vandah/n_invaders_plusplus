#ifndef OBJECT_GAME
#define OBJECT_GAME

#include "object.h"

class player;
class invader;
class bunker;

class game : object {
  public:
  game();

  ~game();

  void reset();

  void redraw() const;

  void toggle_pause();

  /// if player is out of lives, end the game, ask for name and show stats
  void game_over();

  void move_right();

  void move_left();

  void shoot();

  protected:
  int color() const;

  std::vector<std::string> get_looks() const;

  private:
  bool is_paused;

  void load_bunkers();

  void load_invaders();
};

#endif
