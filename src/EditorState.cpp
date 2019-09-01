#include "EditorState.h"

EditorState::EditorState() {}

EditorState::~EditorState() {} 

void EditorState::init(){

}

void EditorState::update(){
	if(_input == 'q'){
		StateHandler::popState();
	}
}

void EditorState::draw(){ 
	mvaddstr(0, 0, "m    m               mmmmmm     #    \"      m");
	mvaddstr(1, 0, "##  ##  mmm   mmmm   #       mmm#  mmm    mm#mm   mmm    m mm");
	mvaddstr(2, 0, "# ## # \"   #  #\" \"#  #mmmmm #\" \"#    #      #    #\" \"#   #\"  ");
	mvaddstr(3, 0, "# \"\" # m\"\"\"#  #   #  #      #   #    #      #    #   #   #");
	mvaddstr(4, 0, "#    # \"mm\"#  ##m#\"  #mmmmm \"#m##  mm#mm    \"mm  \"#m#\"   #");
	mvaddstr(5, 14, "#");
	mvaddstr(6, 14, "\"");
}

void EditorState::clean(){

}
