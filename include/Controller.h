#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"
#include "RepTex.h"
#include "Graph.h"


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
	void rotate(sf::Event event);
	void newLvl();

	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow m_gameWindow;
	sf::Sprite m_background;
	sf::Sprite m_bgMenu;
	std::map<char, pipeTextures>m_charToTexConverter;
	std::map<char, const unsigned int> m_charToDirectionConverter;
	FileHandler m_map;
	std::unique_ptr<RepTex>m_mapOnScreen;

	//Board m_board;
};