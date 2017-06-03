#ifndef SCR_GAME
#define SCR_GAME

#include "../object/game.h"
#include "screen_base.h"

class game;

/// game screen
class scr_game : public screen_base {
  public:
  /// constructor
  scr_game();

  /// destructor
  ~scr_game();

  void handle_timer();

  protected:
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

  private:
  game* Game;

  /// is the game running or paused ?
  bool is_paused;
};
#endif
