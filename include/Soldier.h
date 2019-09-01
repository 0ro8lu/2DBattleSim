#ifndef SOLDIER_H
#define SOLDIER_H

#include "Entity.h"

class Soldier : public Entity{
public:
	Soldier(char s, int x, int y);	
        ~Soldier();	

	void update(std::vector<std::string>& map);
private:
};

#endif // SOLDIER
