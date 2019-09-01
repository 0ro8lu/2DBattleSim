#include <Map.h>

Map::Map() {
	initscr();
	cbreak();
}

Map::~Map() {}

void Map::load(std::string fileName){
	std::fstream file;
	file.open(fileName);

	if(!(file.is_open())){
		std::cout << "Error! Could not open file " << fileName << std::endl;
		exit(1);
	}
	
	//Loading the map
	std::string tmp;
	while(std::getline(file, tmp)){
		_map.push_back(tmp);
	}

	//Processing the map's content
	for(int y = 0; y < _map.size(); y++){
		for(int x = 0; x < _map[y].length(); x++){
			if(_map[y][x] != '.' && _map[y][x] != '#'){
				_army.push_back(new Soldier(_map[y][x], x, y));
			}
		}
	}
	//Soldier s;
	//s.update(_map);

	file.close();
}

void Map::draw(){	
	for(int y = 0; y < _map.size(); y++){
		for(int x = 0; x < _map[y].length(); x++){
			mvaddch(y, x, _map[y][x]);
		}
	}

	printw("%d", _army.size());
	refresh();
}
