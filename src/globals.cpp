#include "globals.h"
#include "main.h"

void show_version(){
	std::cout<<"Version number "<<VERSION<<std::endl;
	finish(0);
}

void show_help(){
	std::cout<<"HELP"<<std::endl;
	//TODO write help
	finish(0);
}

void get_opts(int argc, char** argv){
	for(int i=0;i<argc;++i){
		std::string opt=argv[i];
		if(opt=="--version")show_version();
		else if(opt=="--help"||opt=="-h")show_help();
		//TODO other options
	}
}
