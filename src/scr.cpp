#include "scr.hpp"
#include "main.hpp"

scr::scr():state(0),win(NULL){}

scr::~scr(){}

scr_list::scr_list(const std::vector<std::string> &list_items):selected_idx(0){
	for(auto item:list_items)items.push_back(item); //copy list
	win = newwin(30,40,10,10);
	refresh();
}

scr_list::scr_list(){}

scr_list::~scr_list(){}

void scr_list::draw_list()const{
	waddstr(win,"ahoj");
}

void scr_list::handle_timer(){}//TODO

void scr_list::up(){
	selected_idx--;
	selected_idx%=items.size();
}

void scr_list::down(){
	selected_idx++;
	selected_idx%=items.size();
}

scr_menu::scr_menu():scr_list(){
	items = std::vector<std::string>{"Play","High Scores",
		"Settings","Quit"};
		}

scr_menu::~scr_menu(){}

void scr_menu::redraw()const{scr_list::draw_list();refresh();}

void scr_menu::handle_event(char event){
	switch(event){
		case 10:
			gui.switch_screen(SCR_GAME);
			break;
	}
}
