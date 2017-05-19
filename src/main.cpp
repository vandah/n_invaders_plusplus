/**
 * @mainpage
 * @section Description
 *
 * delsi popis
 *
 * Created by Vanda Hendrychova
 */
#include "main.h"

view gui;

int main(int argc,char ** argv){
	get_opts(argc, argv);
	start_timer();
	while(1)gui.read_input();
	finish();
	return 0;
}

void start_timer(){
	struct itimerval timer;

	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 1000000 / FPS;
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 1000000 / FPS;

	setitimer(ITIMER_REAL, &timer, NULL);

	struct sigaction action;

	action.sa_handler = &handle_timer; /* signal handler function */
	action.sa_flags = SA_RESTART;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGINT);

	sigaction(SIGALRM, &action, NULL);
}

void handle_timer(int sig){gui.handle_timer();}

void finish(){}//TODO implement
