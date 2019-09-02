#include "Game.h"

double Game::_previous = 0;
double Game::_lag      = 0;
double Game::_current  = 0;
double Game::_elapsed  = 0;
const double Game::MS_PER_UPDATE = 1;

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

		mvaddstr(0, 0, std::to_string(_lag).c_str());

		while(_lag >= MS_PER_UPDATE){
			update();
			draw();
			_lag -= MS_PER_UPDATE;
		}
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
}

void Game::clean(){
	StateHandler::clean();
	endwin();
}
