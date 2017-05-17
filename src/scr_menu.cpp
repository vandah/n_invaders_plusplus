#include "scr_menu.hpp"
#include "scr.hpp"
#include "main.hpp"

scr_menu::scr_menu():scr_list(){
	items = std::vector<std::pair<std::string,int>>{{"Play",SCR_GAME},
		{"High Scores",SCR_HISCORE},{"Settings",SCR_SETTINGS},{"Quit",SCR_QUIT}};
	back=SCR_UNDEF;
}

scr_menu::~scr_menu(){}

void scr_menu::redraw()const{scr_list::draw_list();refresh();}

