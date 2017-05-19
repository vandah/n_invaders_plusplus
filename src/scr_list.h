#ifndef SCR_LIST
#define SCR_LIST
#include "scr.h"
///generic screen for listing items
class scr_list:public scr{
	public:
		///constructor
		scr_list();

		///destructor
		~scr_list();

		///print list items
		void draw_list()const;

		///time tick
		void handle_timer();

		///updates the window
		virtual void redraw()const=0;

		///keypress event handler
		void handle_event(int event);
	protected:
		///menu items to print (matched with screens they point to)
		std::vector<std::pair<std::string,int>> items;

		///selected line
		int selected_idx;

		///screen to return to if backspace is pressed
		int back;
};
#endif

