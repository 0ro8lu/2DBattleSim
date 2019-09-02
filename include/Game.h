#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

#include "Timer.h"
#include "MenuState.h"
#include "EditorState.h"

class Game{
public:
	static void init();
	static void initNcurses(); 
	static void update();
	static void draw();
	static void clean();
private:

	static double _previous, _lag, _current, _elapsed;
	static const double MS_PER_UPDATE;
};

#endif //GAME_H
