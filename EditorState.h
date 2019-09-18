#ifndef EDITOR_STATE_H
#define EDITOR_STATE_H

#include "GameState.h"
#include "StateHandler.h"

//probably don't need them
#define MAP_MAX_X 500
#define MAP_MAX_Y 500

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
	WINDOW* _solidWin;
	WINDOW* _enemyWin;
	WINDOW* _teamWin;

	void initWins();
	short _winSelect;
	void drawPointer(WINDOW* win);

	int     _winWidth, _winHeight;
	int     _winStartX, _winStartY;

	int _cursorX, _cursorY;
	int _offsetX, _offsetY;

	//Editor vars
	char  _currentChar;
	short _currentColor;
	bool  _currentSolid;
	bool  _currentEnemy;

	//Map vars
	std::vector<param> _map;
	void fill(char symbol, short color, bool isSolid, bool isEnemy);
};

#endif // EDITOR_STATE_H
