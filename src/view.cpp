#include "view.hpp"
view::view(){
	scr_main=initscr();
	cbreak();
	noecho();
	keypad(scr_main,TRUE);
	rows=LINES;
	cols=COLS;
	refresh();
	current_screen=new scr_menu;
	//TODO
}

view::~view(){}

void view::switch_screen(int s){
	scr *tmp_screen = current_screen;
	switch(s){
		case SCR_MENU:
			current_screen=new scr_menu;
			break;
//		case SCR_GAME:
//			current_screen=new scr_game;
//			break;
//		case SCR_HISCORE:
//			current_screen=new scr_hiscore;
//			break;
//		case SCR_SETTINGS:
//			current_screen=new scr_settings;
//			break;
//		case SCR_QUIT:
//			current_screen=new scr_quit;
//			break;
		default: /*NO DEFINED SCREEN*/
			return;
	}
	delete tmp_screen;
}

void view::read_input(){} //TODO

//void view::refresh(){} //T0DO

void view::handle_timer(){current_screen->handle_timer();}
