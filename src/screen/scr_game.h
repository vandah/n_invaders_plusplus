#ifndef SCR_GAME
#define SCR_GAME

#include "../object/invader.h"
#include "../object/player.h"
#include "screen_base.h"

/// game screen
class scr_game : public screen_base {
  public:
  /// constructor
  scr_game();

  /// destructor
  ~scr_game();

  /// draw the whole screen
  void redraw() const;

  /// move player's ship right
  void key_right();

  /// move player's ship left
  void key_left();

  /// shoot
  void key_up();

  /// pause game
  void key_pause();

  /// exit the current game
  void key_quit();

  /// behaves as key_quit
  void key_backspace();

  /// check whether there are collisions
  void check_conflicts();

  /// is player still alive ?
  void check_state();

  /// if player is out of lives, end the game, ask for name and show stats
  void game_over();

  protected:
  /// grid of invaders
  std::vector<std::vector<invader>> invaders;

  /// the player's ship
  player Player;

  /// is the game running or paused ?
  bool is_paused;
};
#endif
