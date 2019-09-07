#include "EditorState.h"

EditorState::EditorState() {}

EditorState::~EditorState() {} 

void EditorState::init(){
	clear();

	_cursorX = 1;
	_cursorY = 1;

	_offsetX = 0;
	_offsetY = 0;

	_currentChar  = 33;
	_currentColor = 1;

	//Init windows
	_editorWin = newwin(44, 180, 10, 2);
	_charWin   = newwin(3, 3, 10, 184);
	refresh();

	box(_editorWin, 0, 0);
	box(_charWin, 0, 0);

	wrefresh(_editorWin);
	wrefresh(_charWin);

	//Init map
	_map.reserve(MAP_MAX_Y * MAP_MAX_X);
	fill(45, 2, false, false);
}

void EditorState::input(){
	_input = getch();

	if(_input == 10){
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].symbol  = _currentChar;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].color   = _currentColor;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].isSolid = false;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].isEnemy = false;
	}

	if(_input == 'f')
		fill(_currentChar, _currentColor, false, false);

	//Input for char selection
	if(_input == 'w'){
		if(_currentChar == 126)
			_currentChar = 33;
		else
			_currentChar++;
	}

	if(_input == 's'){
		if(_currentChar == 33)
			_currentChar = 126;
		else
			_currentChar--;
	}

	//Input for foreground color selection
	if(_input == 'e'){
		if(_currentColor == 7)
			_currentColor = 0;
		else
			_currentColor++;
	}

	if(_input == 'd'){
		if(_currentColor == 0)
			_currentColor = 7;
		else
			_currentColor--;
	}

	if(_input == KEY_LEFT){
		if(_cursorX == 1 && _offsetX != 0)
			_offsetX--;
		else if(_cursorX != 1)
			_cursorX--;
	}

	if(_input == KEY_RIGHT){
		if(_cursorX == getmaxx(_editorWin) - 2 && _offsetX != (MAP_MAX_X - getmaxx(_editorWin)))
			_offsetX++;
		else if(_cursorX != getmaxx(_editorWin) - 2)
			_cursorX++;
	}

	if(_input == KEY_UP){
		if(_cursorY == 1 && _offsetY != 0)
			_offsetY--;
		else if(_cursorY != 1)
			_cursorY--;
	}

	if(_input == KEY_DOWN){
		if(_cursorY == getmaxy(_editorWin) - 2 && _offsetY != (MAP_MAX_Y - getmaxy(_editorWin)))
			_offsetY++;
		else if(_cursorY != getmaxy(_editorWin) - 2)
			_cursorY++;
	}

	if(_input == 'q'){
		StateHandler::popState();
	}
}

void EditorState::update(){
}

void EditorState::draw(){ 
	mvaddstr(0, ((COLS - 49) / 2), " __  __             ______    _ _ _             ");
	mvaddstr(1, ((COLS - 49) / 2), "|  \\/  |           |  ____|  | (_) |            ");
	mvaddstr(2, ((COLS - 49) / 2), "| \\  / | __ _ _ __ | |__   __| |_| |_ ___  _ __ ");
	mvaddstr(3, ((COLS - 49) / 2), "| |\\/| |/ _` | '_ \\|  __| / _` | | __/ _ \\| '__|");
	mvaddstr(4, ((COLS - 49) / 2), "| |  | | (_| | |_) | |___| (_| | | || (_) | |   ");
	mvaddstr(5, ((COLS - 49) / 2), "|_|  |_|\\__,_| .__/|______\\__,_|_|\\__\\___/|_|   ");
	mvaddstr(6, ((COLS - 49) / 2), "             | |                                ");
	mvaddstr(7, ((COLS - 49) / 2), "             |_|                                ");

	//Char window
	wattron(_charWin, COLOR_PAIR(_currentColor));
	mvwaddch(_charWin, 1, 1, _currentChar);
	wattroff(_charWin, COLOR_PAIR(_currentColor));
	refresh();
	wrefresh(_charWin);

	//Editor window
	for(int y = 0; y < (getmaxy(_editorWin) - 2); y++){
		for(int x = 0; x < (getmaxx(_editorWin) - 2); x++){
			wattron(_editorWin, COLOR_PAIR(_map[(x + _offsetX) + (getmaxx(_editorWin) * (y + _offsetY))].color));
			mvwaddch(_editorWin, y + 1, x + 1, _map[(x + _offsetX) + (getmaxx(_editorWin) * (y + _offsetY))].symbol);
			wattroff(_editorWin, COLOR_PAIR(_map[(x + _offsetX) + (getmaxx(_editorWin) * (y + _offsetY))].color));
		}
	}

	mvaddstr(8, 3, ("X: " + std::to_string(_cursorX + _offsetX)).c_str());
	mvaddstr(9, 3, ("Y: " + std::to_string(_cursorY + _offsetY)).c_str());

	wmove(_editorWin, _cursorY, _cursorX);
	refresh();
	wrefresh(_editorWin);
}

void EditorState::clean(){
	clear();
}

void EditorState::fill(char symbol, short color, bool isSolid, bool isEnemy){
	for(int i = 0; i < (MAP_MAX_X * MAP_MAX_Y); i++){
		_map[i].symbol = symbol;
		_map[i].color = color;
		_map[i].isSolid = isSolid;
		_map[i].isEnemy = isEnemy;
	}
}