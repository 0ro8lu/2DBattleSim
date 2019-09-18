#include "Window.h"

Window::Window(int width, int height, int startX, int startY){
    _win = newwin(height, width, startY, startX);
    refresh();

    box(_win, 0, 0);
    wrefresh(_win);

    _width  = getmaxx(_win);
    _height = getmaxy(_win);
    _startX = getbegx(_win);
    _startY = getbegy(_win);

    _cursorX = 1;
    _cursorY = 1;
}

Window::~Window(){
    
}

void Window::moveCursor(int input){

    if(input == KEY_LEFT){
        if(_cursorX == 1)
            _cursorX = _width - 2;
        else
            _cursorX--;
    }

    if(input == KEY_RIGHT){
        if(_cursorX == _width - 2)
            _cursorX = 1;
        else
            _cursorX++;
    }

    if(input == KEY_DOWN){
        if(_cursorY == _height - 2)
            _cursorY = 1;
        else
            _cursorY++;
    }

    if(input == KEY_UP){
        if(_cursorY == 1)
            _cursorY = _height - 2;
        else
            _cursorY--;
    }
}