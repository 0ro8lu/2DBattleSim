#include "Game.h"

Map Game::_map;
char Game::_onExit = 0;

void Game::init(){	
	//Init NCurses
	initNcurses();

	//Game state initalization
	StateHandler::pushState(new MenuState);

	//_map.load("../../maps/map1.txt");

	while(!(StateHandler::onExit())){
		update();
		draw();
	}
	clean();
}

void Game::initNcurses(){	
	initscr();
	timeout(0);
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	if(has_colors() == FALSE){
		endwin();
		puts("Your terminal does not support colors");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
}
void Game::update(){
	StateHandler::update();
}

void Game::draw(){
	StateHandler::draw();
	//_map.draw();
}

void Game::clean(){
	StateHandler::clean();
	endwin();
}
