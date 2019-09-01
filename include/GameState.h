#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <functional>
#include <ncurses.h>

class GameState{
public:
	GameState();
	virtual ~GameState();

	virtual void init()   = 0;
	virtual void update() = 0;
	virtual void draw()   = 0;
	virtual void clean()  = 0;

protected:
	int _input;
};

#endif // GAME_STATE_H
