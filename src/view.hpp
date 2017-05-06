#ifndef VIEW
#define VIEW

/*ncurses colors*/
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
///GUI
class view{
	public:
		view();
		~view();
		///gets char and sends it to appropriate screen to handle
		void read_input();
		void status_bar(int lvl, int score, int lives);
		void refresh();
		void switch_screen(int s);
	protected:
		int rows,cols;
		WINDOW *scr_main;
		scr *current_screen;
};
#endif
