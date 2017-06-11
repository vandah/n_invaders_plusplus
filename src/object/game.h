#ifndef OBJECT_GAME
#define OBJECT_GAME

#include "object.h"

class game : object {
  public:
  /// default constructor
  game();

  /// default destructor
  ~game();

  /// reset the game - useful when moving to the next level
  void reset() const;

  /// redraw all necessary objects
  void redraw() const;

  /// pause/unpause
  void toggle_pause();

  /// if player is out of lives, end the game, ask for name and show stats
  void game_over() const;

  /// move player's ship right
  void move_right() const;

  /// move player's ship left
  void move_left() const;

  /// let player shoot
  void shoot() const;

  protected:
  /// object's color - useless here but pure virtual in the base class
  int color() const;

  /// available looks - useless here but pure virtual in the base class
  std::vector<std::string> get_looks() const;

  private:
  /// paused/unpaused
  bool is_paused;

  /// check whether the game is paused or over
  bool is_running() const;

  /// print information about level, lives and score
  void print_status_line() const;

  /// load bunkers from file into an array
  void load_bunkers() const;

  /// load invaders into an array
  void load_invaders() const;

  /// clear invaders and their missiles
  void clear_invaders() const;

  /// destroy bunkers to free the space for new level
  void destroy_bunkers() const;

  /// move the invaders grid
  void move_invaders() const;
};

#endif
