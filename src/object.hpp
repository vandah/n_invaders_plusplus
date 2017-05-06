#include "globals.hpp"
class object{
	public:
		object();
		virtual ~object();
		virtual void redraw()=0;
		virtual void destroy()=0;
		virtual void reset()=0;
	protected:
		int size_x, size_y;
		int pos_x, pos_y;
};

class moving:public object{
	public:
		void move(std::pair<int,int> xy);
	protected:
		int state;
};

class falling:public moving{};
class missile:public falling{};
class bonus:public falling{
	public:
		virtual void grant();
};
class smart:public moving{};
class invader:public moving{};
class ufo:public moving{};
class player:public moving{};
