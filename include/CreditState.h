#ifndef CREDIT_STATE_H
#define CREDIT_STATE_H

#include "StateHandler.h"

class CreditState : public GameState{
public:
	CreditState();
	~CreditState();

	void init();
	void update();
	void draw();
	void clean();
private:
	int         _stringLastPos;
	std::string _creator;
	std::string _artist;
	std::string _programmer;
};

#endif // CREDIT_STATE_H
