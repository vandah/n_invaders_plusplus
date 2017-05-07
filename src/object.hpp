#include "globals.hpp"
///generic static object
class object{
	public:
		object(int sx=0,int sy=0,int px=0, int py=0);
		virtual ~object();
		virtual void redraw()=0;
		virtual void destroy()=0;
		void set_pos(std::pair<int,int> xy);
		std::pair<int,int> get_pos();
	protected:
		std::pair<int,int> size;
		std::pair<int,int> pos;
};

///moving object
class moving:public object{
	public:
		void move(std::pair<int,int> xy);
		virtual void reset()=0;
	protected:
		int state;
};

class falling:public moving{
	public:
		void fall(bool down=true);
		void redraw();
		void destroy();
		void reset();
};

class missile:public falling{
	public:
		void redraw();
		void destroy();
};

class bonus:public falling{
	public:
		virtual void grant();
		void redraw();
		void destroy();
};

class smart:public moving{
	public:
		void redraw();
		void destroy();
};

class invader:public moving{
	public:
		void redraw();
		void destroy();
		void reset();
};

class ufo:public moving{
	public:
		void redraw();
		void destroy();
		void reset();
};

class player:public moving{
	public:
		void redraw();
		void destroy();
		void reset();
};
