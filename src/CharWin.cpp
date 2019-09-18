#include "CharWin.h"

CharWin::CharWin(int width, int height, int startX, int startY) : Window(width, height, startX, startY){
    for(unsigned int i = 0; i <= MAX_SYMBOLS; i++){
        if((33 + i) != 65 && (33 + i) != 72 && (33 + i) != 83){
            _symbols.push_back(33 + i);
        }
    }
}

CharWin::~CharWin(){

}

void CharWin::drawWin(){
    
    int cols = 0;
    int rows  = 0;
    for(int i = 0; i < _symbols.size(); i++){
        if(cols == (_width - 2)){
            cols = 0;
            rows++;
        }
        mvwaddch(_win, rows + 1, cols + 1, _symbols[i]);
        cols++;
    }

    if(_isFocused)
        wmove(_win, _cursorY, _cursorX);

    wrefresh(_win);
}

void CharWin::inputWin(int input){
    moveCursor(input);

    if(input == 10){
        _ed.setSymbol(_symbols[_cursorX + ((_cursorY - 1) * (_width - 3))]);
        mvaddch(0, 0, _symbols[_cursorX + (_cursorY * (_width - 3))]);
    }
}