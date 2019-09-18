#include "EditorWin.h"

EditorWin::EditorWin(int width, int height, int startX, int startY) : Window(width, height, startX, startY){
    _offsetX = 0;
    _offsetY = 0;

    _cursorX = 1;
    _cursorY = 1;
	
	_map.reserve(MAP_MAX_X * MAP_MAX_Y);
	_currentSymbol = '.';
	_currentColor  = 2;
	_currentSolid  = false;
	_currentEnemy  = false;
	
	fill();

	_currentSymbol = '#';
	_currentColor  = 2;
}

EditorWin::~EditorWin(){

}

void EditorWin::drawWin(){

    for(int y = 0; y < _height - 2; y++){
		for(int x = 0; x < _width - 2; x++){
			wattron(_win, COLOR_PAIR(_map[(x + _offsetX) + (MAP_MAX_X * (y + _offsetY))].color));
			mvwaddch(_win, y + 1, x + 1, _map[(x + _offsetX) + (MAP_MAX_X * (y + _offsetY))].symbol);
			wattroff(_win, COLOR_PAIR(_map[(x + _offsetX) + (MAP_MAX_X * (y + _offsetY))].color));
		}
	}

	//Clear first, than print coordinates
	mvaddch(_startY - 2, _startX + 5, ' ');
	mvaddch(_startY - 1, _startX + 5, ' ');

	mvaddch(_startY - 2, _startX + 4, ' ');
	mvaddch(_startY - 1, _startX + 4, ' ');

	mvaddstr(_startY - 2, _startX, ("X: " + std::to_string(_cursorX + _offsetX)).c_str());
	mvaddstr(_startY - 1, _startX, ("Y: " + std::to_string(_cursorY + _offsetY)).c_str());

	if(_isFocused)
		wmove(_win, _cursorY, _cursorX);

	wrefresh(_win);
}

void EditorWin::inputWin(int input){
	moveCursor(input);

	if(input == 10){
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * MAP_MAX_X)].symbol  = _currentSymbol;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * MAP_MAX_X)].color   = _currentColor;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * MAP_MAX_X)].isSolid = _currentSolid;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * MAP_MAX_X)].isEnemy = _currentEnemy;
	}
}

void EditorWin::fill(){
	for(int i = 0; i < (MAP_MAX_X * MAP_MAX_Y); i++){
		_map[i].symbol  = _currentSymbol;
		_map[i].color   = _currentColor;
		_map[i].isSolid = _currentSolid;
		_map[i].isEnemy = _currentEnemy;
	}
}

void EditorWin::moveCursor(int input){

	if(input == KEY_LEFT){
		if(_cursorX == 1 && _offsetX != 0)
			_offsetX--;
		else if(_cursorX != 1)
			_cursorX--;
	}
	if(input == KEY_RIGHT){
		if(_cursorX ==_width - 2 && _offsetX != (MAP_MAX_X - _width))
			_offsetX++;
		else if(_cursorX != _width - 2)
			_cursorX++;
	}
	if(input == KEY_UP){
		if(_cursorY == 1 && _offsetY != 0)
			_offsetY--;
		else if(_cursorY != 1)
			_cursorY--;
	}
	if(input == KEY_DOWN){
		if(_cursorY == _height - 2 && _offsetY != (MAP_MAX_Y - _height))
			_offsetY++;
		else if(_cursorY != _height - 2)
			_cursorY++;
	}
}