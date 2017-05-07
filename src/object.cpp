#include "object.hpp"
object::object(int sx,int sy,int px,int py):size({sx,sy}),pos({px,py}){}

object::~object(){}

void object::set_pos(std::pair<int,int> xy){pos=xy;}

std::pair<int,int> object::get_pos(){return pos;}

void moving::move(std::pair<int,int> xy){
	//TODO check if not outside of the window
	std::pair<int,int> curr_pos = get_pos();
	set_pos({curr_pos.first+xy.first,curr_pos.second+xy.second});
}
