#include "globals.h"

void show_version(){
	std::cout<<"Version number 0.0.1-1"<<std::endl;
} //TODO

void get_opts(int argc, char** argv){
	for(int i=0;i<argc;++i){
		std::string opt=argv[i];
		if(opt=="--version")show_version();
	}
} //TODO
