#include "view.hpp"
#include "scr.hpp"
#include "scr_menu.hpp"
#include "scr_hiscore.hpp"
#include "scr_settings.hpp"
#include "scr_quit.hpp"

view::view(){
	scr_main=initscr();
	keypad(stdscr, TRUE);
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
		case SCREEN_MENU:
			current_screen=new scr_menu;
			break;
		case SCREEN_GAME:
			current_screen=new scr_game;
			break;
		case SCREEN_HISCORE:
			current_screen=new scr_hiscore;
			break;
		case SCREEN_SETTINGS:
			current_screen=new scr_settings;
			break;
		case SCREEN_QUIT:
			current_screen=new scr_quit;
			break;
		default: /*NO DEFINED SCREEN*/
			return;
	}
	delete tmp_screen;
}

void view::read_input(){} //TODO

//void view::refresh(){} //T0DO

void view::handle_timer(){current_screen->handle_timer();}
