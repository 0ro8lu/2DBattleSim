#ifndef EDITOR_WIN_H
#define EDITOR_WIN_H

#include "Window.h"
#include <vector>

#define MAP_MAX_X 500
#define MAP_MAX_Y 500

struct param{
    char  symbol;
    short color;
    bool  isSolid;
    bool  isEnemy;
};

class EditorWin : public Window{
public:
    EditorWin(int width, int height, int startX, int startY);
    ~EditorWin();

    void drawWin();
    void inputWin(int input);
    void fill();
    void moveCursor(int input);

private:

    int _offsetX, _offsetY;

    std::vector<param> _map;

    char  _currentSymbol;
	short _currentColor;
	bool  _currentSolid;
	bool  _currentEnemy;
};

#endif // EDITOR_WIN_H