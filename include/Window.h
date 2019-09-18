#ifndef WINDOW_H
#define WINDOW_H

#include "Core.h"
#include <string>

class Window{
public:
    Window(int width, int height, int startX, int startY);
    virtual ~Window();

    int getWidth()  const { return _width; }
    int getHeight() const { return _height; }
    int getStartX() const { return _startX; }
    int getStartY() const { return _startY; }
    WINDOW* getWindow()   { return _win; }
    void setFocus(bool f) { _isFocused = f; }

    virtual void drawWin() = 0;
    virtual void inputWin(int input) = 0;


protected:
    void moveCursor(int input);

    int _width, _height;
    int _startX, _startY;
    int _cursorX, _cursorY;
    bool _isFocused;

    WINDOW* _win;
};

#endif //WINDOW_H