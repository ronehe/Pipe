#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"
#include "RepTex.h"


//#include "iostream"

#pragma once

class Controller {

public:
	Controller();
	void startGame();//the game loop
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~//
private:
	//creates the window and the outlines
	void generateBackgrounds();
	void updateDataStructures();
	void createCharToTexCoverter();
	void rotate(sf::Event event);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow m_gameWindow;
	sf::Sprite m_background;
	sf::Sprite m_bgMenu;
	std::map<char, pipeTextures>m_charToTexConverter;
	RepTex m_mapOnScreen;
	FileHandler m_map;
	Board m_board;
};