#include "CreditState.h"

CreditState::CreditState() {}

CreditState::~CreditState() {}

void CreditState::init(){
	clear();	

	_creator    = "Creator: ME ^^";
	_artist     = "Artist: also ME ^^";
	_programmer = "Programmer: The best that ever lived, ME ^^";

	_stringLastPos = LINES / 2;
}

void CreditState::input(){
	_input = getch();

	if(_input == 'q'){
		clear();
		StateHandler::popState();	
	}
}

void CreditState::update(){
	clear();
	_stringLastPos--;
}

void CreditState::draw(){
	mvaddstr(0, (COLS - 70)/2, "    mmmm                             mm     ##                        ");
	mvaddstr(1, (COLS - 70)/2, "  ##\"\"\"\"#                            ##     \"\"       ##               ");
	mvaddstr(2, (COLS - 70)/2, " ##\"        ##m####   m####m    m###m##   ####     #######   mm#####m ");
	mvaddstr(3, (COLS - 70)/2, " ##         ##\"      ##mmmm##  ##\"  \"##     ##       ##      ##mmmm \" ");
	mvaddstr(4, (COLS - 70)/2, " ##m        ##       ##\"\"\"\"\"\"  ##    ##     ##       ##       \"\"\"\"##m ");
	mvaddstr(5, (COLS - 70)/2, "  ##mmmm#   ##       \"##mmmm#  \"##mm###  mmm##mmm    ##mmm   #mmmmm## ");
	mvaddstr(6, (COLS - 70)/2, "    \"\"\"\"    \"\"         \"\"\"\"\"     \"\"\" \"\"  \"\"\"\"\"\"\"\"     \"\"\"\"    \"\"\"\"\"\"  ");

	if(_stringLastPos >= 17)
		mvaddstr(_stringLastPos - 7, ((COLS - _creator.length()) / 2), _creator.c_str());
	
	if(_stringLastPos >= 17 - 1)
		mvaddstr(_stringLastPos - 6, ((COLS - _artist.length()) / 2), _artist.c_str());
	
	if(_stringLastPos >= 17 - 2)
		mvaddstr(_stringLastPos - 5, ((COLS - _programmer.length()) / 2), _programmer.c_str());
}

void CreditState::clean(){
}
