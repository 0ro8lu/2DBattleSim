#ifndef STATE_HANDLER_H
#define STATE_HANDLER_H

#include "GameState.h"
#include <vector>

class StateHandler{
public:
	static void pushState(GameState* gs);
	static void popState();
	static void update();
	static void draw();
	static void clean();

	static void shouldExit();
	static bool onExit();

private:
	static std::vector<GameState*> _gameStates;
	static bool _onExit;
};

#endif // STATE_HANDLER_H
