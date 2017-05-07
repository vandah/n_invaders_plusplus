#include "scr.hpp"
scr::scr():state(0),win(NULL){}

void scr::set_state(int s){state=s;}

int scr::get_state()const{return state;}

void scr::set_win(WINDOW*w){win=w;}

WINDOW* scr::get_win()const{return win;}

scr_list::scr_list(const std::string* &list_items){}
