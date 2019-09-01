#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

class Entity{
public:
	Entity();
	virtual ~Entity();	

	/*
	char getSymbol() const { return _symbol; }
	int  getX()      const { return _x;      }
	int  getY()      const { return _y;      }
	int  getHealth() const { return _health; }
	int  getAttack() const { return _attack; }
	*/

	virtual void update(std::vector<std::string>& map) = 0;

protected:
	char _symbol;
	int _x, _y;
	int _health;
	int _minAttack;
	int _maxAttack;
};

#endif //ENTITY
