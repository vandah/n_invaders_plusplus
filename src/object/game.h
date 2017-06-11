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

  void reset() const;

  void redraw() const;

  void toggle_pause();

  /// if player is out of lives, end the game, ask for name and show stats
  void game_over() const;

  void move_right() const;

  void move_left() const;

  void shoot() const;

  protected:
  int color() const;

  std::vector<std::string> get_looks() const;

  private:
  bool is_paused;

  bool is_running() const;

  void print_status_line() const;

  void load_bunkers() const;

  void load_invaders() const;
  
  void clear_invaders() const;

  void destroy_bunkers() const;

  void move_invaders() const;
};

#endif
