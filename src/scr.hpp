#include "globals.hpp"
class scr{
	public:
		virtual ~scr()=0;
		virtual void redraw()const=0;
		virtual void handle_event(char event)=0;
	protected:
		int state;
		WINDOW *win;
};

class scr_list:public scr{
	public:
		scr_list(std::string *list_items);
		void draw_list();
	protected:
		std::string *items;
};

class scr_menu:public scr_list{
	public:
		scr_menu();
		~scr_menu();
		void redraw()const;
		void handle_event(char event);
};

class scr_settings:public scr_list{
	public:
		scr_settings();
		~scr_settings();
		void redraw()const;
		void handle_event(char event);
};

class scr_hiscore:public scr_list{
	public:
		scr_hiscore();
		~scr_hiscore();
		void redraw()const;
		void handle_event(char event);
};

class scr_game:public scr{
	public:
		scr_game();
		~scr_game();
		void redraw()const;
		void handle_event(char event);
};

class scr_quit:public scr{
	public:
		scr_quit();
		~scr_quit();
		void redraw()const;
		void handle_event(char event);
};
