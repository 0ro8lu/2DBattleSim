#include "MenuState.h"

MenuState::MenuState() {}

MenuState::~MenuState() {}

void MenuState::init(){
	clear();

	_subMenus.push_back(std::pair<std::string, std::function<void()>>("Editor",    std::bind(&MenuState::onEditor, this)));
	_subMenus.push_back(std::pair<std::string, std::function<void()>>("Simulator", std::bind(&MenuState::onSimulator, this)));
	_subMenus.push_back(std::pair<std::string, std::function<void()>>("Credits",   std::bind(&MenuState::onCredits, this)));
	_subMenus.push_back(std::pair<std::string, std::function<void()>>("Exit",     std::bind(&MenuState::onExit, this)));

	_currentSelection = 0;
	_selectionPressed = false;
}

void MenuState::update(){
	_input = getch();

	//input managing for menus
	if(_input == KEY_UP){
		if(_currentSelection == 0){
			_currentSelection = _subMenus.size() - 1;
		}else{
			_currentSelection--;
		}
	}

	if(_input == KEY_DOWN){
		if(_currentSelection == _subMenus.size() - 1){
			_currentSelection = 0;
		}else{
			_currentSelection++;
		}
	}
	if(_input == 10){
		_selectionPressed = true;	
	}
}

void MenuState::draw(){

	// Main Menu ASCII String
	mvaddstr(0, (COLS-53)/2, "m    m          \"           m    m");
	mvaddstr(1, (COLS-53)/2, "##  ##  mmm   mmm    m mm   ##  ##  mmm   m mm   m   m");
	mvaddstr(2, (COLS-53)/2, "# ## # \"   #    #    #\"  #  # ## # #\"  #  #\"  #  #   # ");
	mvaddstr(3, (COLS-53)/2, "# \"\" # m\"\"\"#    #    #   #  # \"\" # #\"\"\"\"  #   #  #   #");
	mvaddstr(4, (COLS-53)/2, "#    # \"mm\"#  mm#mm  #   #  #    # \"#mm\"  #   #  \"mm\"#");

	//Sub Menus
	for(unsigned int i = 0; i < _subMenus.size(); i++){
		if(_currentSelection == i){
			attron(COLOR_PAIR(1));
			mvaddstr((6 + i), ((COLS - _subMenus[i].first.length())/2), _subMenus[i].first.c_str());
			attroff(COLOR_PAIR(1));

			if(_selectionPressed){

				_selectionPressed = false;
				_subMenus[i].second();
				break;
			}
		}

		if(_currentSelection != i){
			attroff(COLOR_PAIR(1));
			mvaddstr((6 + i), ((COLS - _subMenus[i].first.length())/2), _subMenus[i].first.c_str());
		}
	}
}

void MenuState::clean(){
}

//Function pointers
void MenuState::onEditor(){

}

void MenuState::onSimulator(){

}

void MenuState::onCredits(){
	StateHandler::pushState(new CreditState);
}

void MenuState::onExit(){
	StateHandler::shouldExit();
}
