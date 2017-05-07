#include "globals.hpp"
#ifndef SCR
#define SCR
class scr{
	public:
		///variable inicialization
		scr();
		
		///screen state handling
		void set_state(int s);

		///screen state handling
		int get_state()const;

		///screen main window handling
		void set_win(WINDOW*w);

		///screen main window handling
		WINDOW* get_win()const;
		
		///destructor
		virtual ~scr()=0;

		///updates the window
		virtual void redraw()const=0;

		///keypress event handler
		virtual void handle_event(char event)=0;

		///time tick
		virtual void handle_timer()=0;

	protected:
		///screens are moving between several states
		int state;

		///the main window
		WINDOW *win;
};

class scr_list:public scr{
	public:
		scr_list(const std::string* &list_items);
		void draw_list();
		void handle_timer();
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
		void handle_timer();
};

class scr_quit:public scr{
	public:
		scr_quit();
		~scr_quit();
		void redraw()const;
		void handle_event(char event);
		void handle_timer();
};
#endif
