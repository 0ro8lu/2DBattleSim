#ifndef EDITOR_STATE_H
#define EDITOR_STATE_H

#include "StateHandler.h"
#include "EditorWin.h"
#include "CharWin.h"

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
	void initWins();

	std::vector<Window*> _windows;

	int _editWinStartX, _editWinStartY;
	int _editWinWidth, _editWinHeight;
	int _currentWindow;
};

#endif // EDITOR_STATE_H
