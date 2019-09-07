#include "Game.h"

double Game::_previous = 0;
double Game::_lag      = 0;
double Game::_current  = 0;
double Game::_elapsed  = 0;
const double Game::MS_PER_UPDATE = 0.99;

void Game::init(){	
	//Init NCurses
	initNcurses();

	//Game state initalization
	StateHandler::pushState(new MenuState);

	_previous = Timer::getCurrentTime();
	while(!(StateHandler::onExit())){

		_current = Timer::getCurrentTime();
		_elapsed = _current - _previous;
		_previous = _current;
		_lag += _elapsed;

		input();

		while(_lag >= MS_PER_UPDATE){
			update();
			_lag -= MS_PER_UPDATE;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
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

	//Initialize all possible color pairs
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_BLACK);
}

void Game::input(){
	StateHandler::input();
}

void Game::update(){
	StateHandler::update();
}

void Game::draw(){
	StateHandler::draw();
}

void Game::clean(){
	StateHandler::clean();
	endwin();
}