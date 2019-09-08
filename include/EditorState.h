#ifndef EDITOR_STATE_H
#define EDITOR_STATE_H

#include "GameState.h"
#include "StateHandler.h"

//probably don't need them
#define MAP_MAX_X 500
#define MAP_MAX_Y 500

struct param{
    char  symbol;
    short color;
    bool  isSolid;
    bool  isEnemy;
};

class EditorState : public GameState{
public:
	EditorState();
	~EditorState();

	void init();
	void input();
	void update();
	void draw();
	void clean();

private:

	//NCurses vars
	WINDOW* _editorWin;
	WINDOW* _charWin;
	int     _winWidth, _winHeight;
	int     _winStartX, _winStartY;

	int _cursorX, _cursorY;
	int _offsetX, _offsetY;

	//Editor vars
	char  _currentChar;
	short _currentColor;

	//Map vars
	std::vector<param> _map;
	void fill(char symbol, short color, bool isSolid, bool isEnemy);
};

#endif // EDITOR_STATE_H
