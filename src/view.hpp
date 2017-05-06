/**
 * \file view.hpp
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

#define SCR_MENU 0
#define SCR_GAME 1
#define SCR_HISCORE 2
#define SCR_SETTINGS 3
#define SCR_QUIT 4

#include "globals.hpp"
#include "scr.hpp"

///GUI basics
class view{
	public:
		view();
		~view();

		///gets char and sends it to the appropriate screen to handle
		void read_input();

		///top bar indicating game status
		void status_bar(int lvl, int score, int lives);

		///refresh gui - FIXME delete?
		void refresh();

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
