#ifndef SCR_GAME
#define SCR_GAME
#include "scr.hpp"
///game screen
class scr_game:public scr{
	public:
		scr_game();
		~scr_game();
		void redraw()const;
		void handle_event(int event);
		void handle_timer();
};
#endif
