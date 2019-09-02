#include "EditorState.h"

EditorState::EditorState() {}

EditorState::~EditorState() {} 

void EditorState::init(){
	clear();
}

void EditorState::update(){
	_input = getch();

	if(_input == 'q'){
		StateHandler::popState();
	}
}

void EditorState::draw(){ 
	mvaddstr(0, ((COLS - 49) / 2), " __  __             ______    _ _ _             ");
	mvaddstr(1, ((COLS - 49) / 2), "|  \\/  |           |  ____|  | (_) |            ");
	mvaddstr(2, ((COLS - 49) / 2), "| \\  / | __ _ _ __ | |__   __| |_| |_ ___  _ __ ");
	mvaddstr(3, ((COLS - 49) / 2), "| |\\/| |/ _` | '_ \\|  __| / _` | | __/ _ \\| '__|");
	mvaddstr(4, ((COLS - 49) / 2), "| |  | | (_| | |_) | |___| (_| | | || (_) | |   ");
	mvaddstr(5, ((COLS - 49) / 2), "|_|  |_|\\__,_| .__/|______\\__,_|_|\\__\\___/|_|   ");
	mvaddstr(6, ((COLS - 49) / 2), "             | |                                ");
	mvaddstr(6, ((COLS - 49) / 2), "             |_|                                ");
}

void EditorState::clean(){
	clear();
}
