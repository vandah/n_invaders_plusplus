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

  /// react to time tick
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

  // behaves as key_up
  void key_space();

  /// pause game
  void key_pause();

  /// exit the current game
  void key_quit();

  /// behaves as key_quit
  void key_backspace();

  /// quit the game and switch screen
  void quit() const;

  private:
  /// the actual game
  game* Game;

  /// is the game running or paused ?
  bool is_paused;
};
#endif
