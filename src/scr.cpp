#include "scr.hpp"
#include "main.hpp"

scr::scr():state(0),win(NULL){}

scr::~scr(){}

void scr::set_state(int s){state=s;}

int scr::get_state()const{return state;}

void scr::set_win(WINDOW*w){win=w;}

WINDOW* scr::get_win()const{return win;}

scr_list::scr_list(const std::vector<std::string> &list_items):selected_idx(0){
	for(auto item:list_items)items.push_back(item); //copy list
}

scr_list::~scr_list(){}

void scr_list::draw_list(){} //TODO

void scr_list::handle_timer(){}//TODO

void scr_list::up(){
	selected_idx--;
	selected_idx%=items.size();
}

void scr_list::down(){
	selected_idx++;
	selected_idx%=items.size();
}

scr_menu::scr_menu():scr_list(std::vector<std::string>{"Play","High Scores",
		"Settings","Quit"}){}

scr_menu::~scr_menu(){}

void scr_menu::redraw()const{}

void scr_menu::handle_event(char event){
	switch(event){
		case 10:
			gui.switch_screen(SCR_GAME);
			break;
	}
}
