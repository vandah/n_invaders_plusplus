#ifndef SCR
#define SCR

#include "globals.hpp"
#include <vector>

class scr{
	public:
		///variable inicialization
		scr();

		///destructor
		virtual ~scr();

		///updates the window
		virtual void redraw()const=0;

		///keypress event handler
		virtual void handle_event(int event)=0;

		///time tick
		virtual void handle_timer()=0;

	protected:
		///screens are moving between several states
		int state;

		///the main window
		WINDOW *win;
};

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
