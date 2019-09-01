#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

#include "Map.h"
#include "StateHandler.h"
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
	static Map _map;
	static char _onExit;
};

#endif //GAME_H
