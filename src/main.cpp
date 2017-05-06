/** 
 * @mainpage
 * @section Description
 * 
 * delsi popis
 * 
 * Created by Vanda Hendrychova
 */
#include "main.hpp"
int main(int argc,char ** argv){
	get_opts(argc, argv);	// evaluate command line parameters
	start_timer();
	view gui;
	while(1)gui.read_input();
	return 0;
}

