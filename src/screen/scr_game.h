#ifndef SCR_GAME
#define SCR_GAME

#include "../object/invader.h"
#include "../object/object.h"
#include "../object/player.h"
#include "screen_base.h"

class invader;
class player;

/// game screen
class scr_game : public screen_base {
  public:
  /// constructor
  scr_game();

  /// destructor
  ~scr_game();

  void handle_timer();

  protected:
  class bunkers : public object {
public:
    bunkers();
    ~bunkers();
    void display();
    void reset();
    void load();
    void remove(std::pair<int, int> xy);

protected:
    std::vector<std::string> get_looks() const;
    std::vector<std::vector<int>> bunker;
    int color() const;
  };

  std::vector<std::vector<int>> battlefield;

  /// draw the whole screen
  void redraw() const;

  /// check whether there are collisions
  void check_conflicts();

  void check_player_conflicts();

  /// is player still alive ?
  void check_state();

  /// if player is out of lives, end the game, ask for name and show stats
  void game_over();

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

  /// grid of invaders
  std::vector<invader*> invaders;

  /// the player's ship
  player* Player;

  bunkers* Bunkers;

  /// is the game running or paused ?
  bool is_paused;
};
#endif
