#include "Soldier.h"

Soldier::Soldier(char s, int x, int y) {
	_symbol = s;
	_x      = x;
	_y      = y;

	_health = 10;
	_minAttack = 1;
	_maxAttack = 10;
}

Soldier::~Soldier() {}

void Soldier::update(std::vector<std::string>& map){
	map[5][5] = 'G';
}
