#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ncurses.h>

#include "Soldier.h"

class Map{
public:
	Map();
	~Map();

	void load(std::string fileName);
	void draw();

private:
	std::vector<std::string> _map;
	std::vector<Entity*> _army;
};

#endif //MAP_H
