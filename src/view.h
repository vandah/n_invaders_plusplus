/**
 * \file view.h
 * Screen wrapper, used for basic GUI manipulation.
 */

#ifndef VIEW
#define VIEW

//ncurses colors
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define CYAN 5
#define MAGENTA 6
#define WHITE 7

#define SCREEN_MENU 0
#define SCREEN_GAME 1
#define SCREEN_HISCORE 2
#define SCREEN_SETTINGS 3
#define SCREEN_QUIT 4
#define SCREEN_UNDEF 5

#include "globals.h"
#include "scr.h"

///GUI basics
class view{
	public:
		view();
		~view();
		void init();

		///gets char and sends it to the appropriate screen to handle
		void read_input();

		///top bar indicating game status
		void status_bar(int lvl, int score, int lives);

		///refresh gui - FIXME delete?
		//		void refresh();

		///switch to another screen
		void switch_screen(int s);

		///receives time tick and alerts the appropriate screen
		void handle_timer();

	protected:
		///screen dimensions - x
		int cols;

		///screen dimensions - y
		int rows;

		///main window
		WINDOW *scr_main;

		///pointer to the current screen - to enable switching
		scr *current_screen;
};
#endif
