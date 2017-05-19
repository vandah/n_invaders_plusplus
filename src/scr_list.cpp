#include "scr_list.h"
#include "main.h"

scr_list::scr_list():selected_idx(0){
	win = newwin(30,40,10,10);
	refresh();
}

scr_list::~scr_list(){}

void scr_list::draw_list()const{
	waddstr(win,"ahoj");
}

void scr_list::handle_timer(){
	handle_event(wgetch(win));
	redraw();
}

void scr_list::handle_event(int event){
	switch(event){
		case 'l':
		case 10:
		case KEY_ENTER:
			gui.switch_screen(items[selected_idx].second);
			break;
		case 'k':
		case KEY_UP:
		  	selected_idx--;
			selected_idx%=items.size();
			break;
		case 'j':
		case KEY_DOWN:
			selected_idx++;
			selected_idx%=items.size();
			break;
		case 'h':
		case 8:
		case 127:
		case KEY_BACKSPACE:
			gui.switch_screen(back);
			break;
		default:
			break;
	}
}

