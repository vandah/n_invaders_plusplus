#ifndef MENU_SCREEN
#define MENU_SCREEN

#include "scr_list.h"

///main menu screen
class scr_menu:public scr_list{
	public:
		scr_menu();

		~scr_menu();

		void redraw()const;
	protected:
		std::vector<int> screen_items;
};
#endif
