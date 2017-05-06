#include "view.hpp"
void view::init_view(){
	scr_main=initscr();
	cbreak();
	noecho();
	keypad(scr_main,TRUE);
	rows=LINES;
	cols=COLS;
	//TODO
}

void view::switch_screen(int s){
	scr *tmp_screen = current_screen;
	switch(s){
		case SCR_MENU:
			current_screen=new scr_menu;
			break;
		case SCR_GAME:
			current_screen=new scr_game;
			break;
		case SCR_HISCORE:
			current_screen=new scr_hiscore;
			break;
		case SCR_QUIT:
			current_screen=new scr_quit;
			break;
		default: /*NO DEFINED SCREEN*/
			return;
	}
	delete tmp_screen;
}
