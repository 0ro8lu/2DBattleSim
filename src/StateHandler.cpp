#include "StateHandler.h"

std::vector<GameState*> StateHandler::_gameStates;
bool StateHandler::_onExit = false;

void StateHandler::pushState(GameState* gs){
	_gameStates.push_back(gs);
	_gameStates[_gameStates.size() - 1]->init();
}

void StateHandler::popState(){
	_gameStates[_gameStates.size() - 1]->clean();
	delete _gameStates[_gameStates.size() - 1];
	_gameStates.pop_back();
}

void StateHandler::update(){
	_gameStates[_gameStates.size() - 1]->update();
}

void StateHandler::draw(){
	_gameStates[_gameStates.size() - 1]->draw();
}

void StateHandler::shouldExit(){
	_onExit = true;	
}

bool StateHandler::onExit(){
	return _onExit;
}

void StateHandler::clean(){
	for(unsigned int i = 0; i < _gameStates.size(); i++){
		_gameStates[i]->clean();
	delete _gameStates[i];
	}
}
