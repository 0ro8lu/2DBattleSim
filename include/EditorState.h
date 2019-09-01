#ifndef EDITOR_STATE_H
#define EDITOR_STATE_H

#include <ncurses.h>

#include "GameState.h"
#include "StateHandler.h"

class EditorState : public GameState{
public:
	EditorState();
	~EditorState();

	void init();
	void update();
	void draw();
	void clean();

private:
};

#endif // EDITOR_STATE_H
