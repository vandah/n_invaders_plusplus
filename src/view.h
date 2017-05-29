/**
 * \file view.h
 * Screen wrapper, used for basic GUI manipulation.
 */

#ifndef VIEW
#define VIEW

#define SCREEN_MENU 0
#define SCREEN_GAME 1
#define SCREEN_HISCORE 2
#define SCREEN_SETTINGS 3
#define SCREEN_QUIT 4
#define SCREEN_UNDEF 5

#define FREE 0
#define INVADER_1 1
#define INVADER_2 2
#define INVADER_3 3
#define INVADER_4 4
#define UFO 5
#define INVADER_MISSILE 6
#define BUNKER 7
#define PLAYER_MISSILE 8
#define PLAYER 9

#include "globals.h"

class screen_base;

/// GUI basics
class view {
  public:
  view();
  ~view();

  void init();

  /// top bar indicating game status
  void status_bar(int lvl, int score, int lives);

  /// switch to another screen
  void switch_screen(int s);

  /// receives time tick and alerts the appropriate screen
  void handle_timer();

  /// screen dimensions - x
  int cols;

  /// screen dimensions - y
  int rows;

  protected:
  /// main window
  WINDOW* scr_main;

  /// pointer to the current screen - to enable switching
  screen_base* current_screen;
};
#endif
