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
	sf::Sprite m_background;
	sf::Sprite m_bgMenu;

	
	Board m_board;

};