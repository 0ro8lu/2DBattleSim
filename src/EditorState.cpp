#include "EditorState.h"

EditorState::EditorState() {}

EditorState::~EditorState() {} 

void EditorState::init(){
	clear();

	_editWinStartX = 2;
	_editWinStartY = 9;
	_editWinWidth  = COLS - 40;
	_editWinHeight = LINES - 10;

	_currentWindow = 0;

	initWins();

	//EditorWin *editorWin = new EditorWin(_editWinWidth, _editWinHeight, _editWinStartX, _editWinStartY);
	//_windows.push_back(editorWin);
}

void EditorState::input(){
	_input = wgetch(_windows[_currentWindow]->getWindow());

	/*
	if(_input == 10){
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].symbol  = _currentChar;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].color   = _currentColor;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].isSolid = _currentSolid;
		_map[((_cursorX + _offsetX) - 1) + (((_cursorY + _offsetY) - 1) * getmaxx(_editorWin))].isEnemy = false;
	}
	*/

	for(unsigned int i = 0; i < _windows.size(); i++){
		if(_currentWindow == i){
			_windows[i]->inputWin(_input);
			_windows[i]->setFocus(true);
		}
		else
			_windows[i]->setFocus(false);
	}

	if(_input == '\t'){
		if(_currentWindow == _windows.size())
			_currentWindow = 0;
		else
			_currentWindow++;
	}

	/*
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
	*/

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

	for(int i = 0; i < _windows.size(); i++)
		_windows[i]->drawWin();

	refresh();
}

void EditorState::clean(){
	clear();

	for(unsigned int i = 0; i < _windows.size(); i++)
		delete _windows[i];
}

void EditorState::initWins(){
	_windows.push_back(new EditorWin(_editWinWidth, _editWinHeight, _editWinStartX, _editWinStartY));
	_windows.push_back(new CharWin(33, 5, (_editWinStartX + _editWinWidth + 4), _editWinStartY));

	for(unsigned int i = 0; i < _windows.size(); i++){
		wtimeout(_windows[i]->getWindow(), 0);
		keypad(_windows[i]->getWindow(), TRUE);
	}
}