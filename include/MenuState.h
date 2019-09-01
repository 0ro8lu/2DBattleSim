#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "StateHandler.h"
#include "CreditState.h"
#include <string>
#include <vector>

class MenuState : public GameState{
public:
	MenuState();
	~MenuState();

	void init();
	void update();
	void draw();
	void clean();

	//Function pointers
	void onEditor();
	void onSimulator();
	void onCredits();
	void onExit();

private:
	std::vector<std::pair<std::string, std::function<void()>>> _subMenus;
	int   			           _currentSelection;
	bool                       _selectionPressed;
};
#endif // MENU_STATE_H