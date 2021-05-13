#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>


//#include "iostream"

#pragma once

class Controller {

public:
	Controller();
	void startGame();//the game loop



	//~~~~~~~~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~//
private:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//

private:
	sf::RenderWindow m_gameWindow;
	Board m_board;

	//std::make_unique<<std::vector<Tool*>>m_Chess_Pieces[2];
	//std::vector<std::vector<Tool*>>m_Chess_Pieces[2];
};