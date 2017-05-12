#ifndef SCR
#define SCR

#include "globals.hpp"
#include <vector>

class scr{
	public:
		///variable inicialization
		scr();

		///destructor
		virtual ~scr();

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

///generic screen for listing items
class scr_list:public scr{
	public:
		scr_list(const std::vector<std::string> &list_items);

		scr_list();

		///destructor
		~scr_list();

		///print list items
		void draw_list()const;

		///time tick
		void handle_timer();

		///move selected idx up
		void up();

		///move selected idx down
		void down();

		///updates the window
		virtual void redraw()const=0;

		///keypress event handler
		virtual void handle_event(char event)=0;
	protected:
		///menu items to print
		std::vector<std::string> items;

		///selected line
		int selected_idx;
};

///main menu screen
class scr_menu:public scr_list{
	public:
		scr_menu();
		~scr_menu();
		void redraw()const;
		void handle_event(char event);
	protected:
		std::vector<int> screen_items;
};

///game settings
class scr_settings:public scr_list{
	public:
		scr_settings();
		~scr_settings();
		void redraw()const;
		void handle_event(char event);
};

///show high scores
class scr_hiscore:public scr_list{
	public:
		scr_hiscore();
		~scr_hiscore();
		void redraw()const;
		void handle_event(char event);
};

///game screen
class scr_game:public scr{
	public:
		scr_game();
		~scr_game();
		void redraw()const;
		void handle_event(char event);
		void handle_timer();
};

///bye bye and quit
class scr_quit:public scr{
	public:
		scr_quit();
		~scr_quit();
		void redraw()const;
		void handle_event(char event);
		void handle_timer();
};
#endif
