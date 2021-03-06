#include "EditorState.h"

EditorState::EditorState() {}

EditorState::~EditorState() {} 

void EditorState::init(){
	clear();

	_winSelect = 0;

	_winWidth  = COLS - 40;
	_winHeight = LINES - 10;
	_winStartX = 2;
	_winStartY = 9;

	//Init Windows
	initWins();

	_cursorX = 2;
	_cursorY = 2;
	_offsetX = 0;
	_offsetY = 0;

	_currentChar  = 33;
	_currentColor = 4;
	_currentSolid = false;
	_currentEnemy = false;

	//Init map
	_map.reserve(MAP_MAX_Y * MAP_MAX_X);
	fill(45, 2, false, false);
}

void EditorState::input(){
	_input = getch();

	if(_input == 9){ //Tab
		if(_winSelect == 4)
			_winSelect = 0;
		else
			_winSelect++;
	}

	if(_input == KEY_CONTROL_R){
		mvaddstr(1, 0, "Control Premuto");
		if(_winSelect == 0){
			_winSelect = 4;
		}
		else{
			_winSelect--;
		}
	}

	if(_input == 10){
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].symbol  = _currentChar;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].color   = _currentColor;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].isSolid = _currentSolid;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].isEnemy = false;
	}

	if(_input == 'a'){
		if(_currentSolid == false){
			_currentSolid = true;
			return;
		}
		if(_currentSolid == true){
			_currentSolid = false;
			return;
		}
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

	if(_input == 'e'){
		if(_currentChar == 33)
			_currentChar = 126;
		else
			_currentChar--;
	}

	//Input for foreground color selection
	if(_input == 's'){
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

	//Editor window
	if(_winSelect == 0)
		drawPointer(_editorWin);

	for(int y = 0; y < (getmaxy(_editorWin) - 2); y++){
		for(int x = 0; x < (getmaxx(_editorWin) - 2); x++){
			wattron(_editorWin, COLOR_PAIR(_map[(x + _offsetX) + (getmaxx(_editorWin) * (y + _offsetY))].color));
			mvwaddch(_editorWin, y + 1, x + 1, _map[(x + _offsetX) + (getmaxx(_editorWin) * (y + _offsetY))].symbol);
			wattroff(_editorWin, COLOR_PAIR(_map[(x + _offsetX) + (getmaxx(_editorWin) * (y + _offsetY))].color));
		}
	}

	//Char window
	if(_winSelect == 1)
		drawPointer(_charWin);
	
	wattron(_charWin, COLOR_PAIR(_currentColor));
	mvwaddch(_charWin, 1, 1, _currentChar);
	wattroff(_charWin, COLOR_PAIR(_currentColor));
	wrefresh(_charWin);

	//Solid Win
	if(_winSelect == 2)
		drawPointer(_solidWin);

	if(_currentSolid){
		wattron(_solidWin, COLOR_PAIR(6));
		mvwaddstr(_solidWin, 1, 1, "         ");
		mvwaddstr(_solidWin, 1, 1, "Solid");
		wrefresh(_solidWin);
	}
	else{
		wattron(_solidWin, COLOR_PAIR(2));
		mvwaddstr(_solidWin, 1, 1, "         ");
		mvwaddstr(_solidWin, 1, 1, "Non Solid");
		wrefresh(_solidWin);
	}

	mvaddstr(_winStartY - 2, _winStartX, ("X: " + std::to_string(_cursorX + _offsetX)).c_str());
	mvaddstr(_winStartY - 1, _winStartX, ("Y: " + std::to_string(_cursorY + _offsetY)).c_str());
	mvaddstr(0, 0, std::to_string(_winSelect).c_str());
	
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

void EditorState::initWins(){

	_editorWin = newwin(_winHeight, _winWidth, _winStartY, _winStartX);
	_charWin   = newwin(3, 4, _winStartY, (_winWidth + _winStartX) + 4); 
	_solidWin  = newwin(3, 11, _winStartY + 3, (_winWidth + _winStartX) + 4);
	_enemyWin  = newwin(3, 11, _winStartY + 6, (_winWidth + _winStartX) + 4);
	_teamWin   = newwin(3, 11, _winStartY + 9, (_winWidth + _winStartX) + 4);

	box(_editorWin, 0, 0);
	box(_charWin, 0, 0);
	box(_solidWin, 0, 0);
	box(_enemyWin, 0, 0);
	box(_teamWin, 0, 0);

	refresh();
	wrefresh(_editorWin);
	wrefresh(_charWin);
	wrefresh(_solidWin);
	wrefresh(_enemyWin);
	wrefresh(_teamWin);
}

void EditorState::drawPointer(WINDOW* win){
	mvaddstr((getbegy(win) + (getmaxy(win) / 2)), (getbegx(win)) - 2, "->");
	refresh();
}