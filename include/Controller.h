#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "FileHandler.h"
#include "RepTex.h"
#include "Graph.h"


//#include "iostream"


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
	bool newLvl();
	void printNextLvlTex();
	void printEndGameTex();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~//
private:
	sf::RenderWindow m_gameWindow;
	sf::Sprite m_background;
	sf::Sprite m_bgMenu;

	sf::Text m_timeText;
	sf::Text m_rotationText;
	sf::Text m_lvlText;
	sf::Sound m_finishedLvlSound;
	sf::Clock m_clock;
	std::map<char, pipeTextures>m_charToTexConverter;
	std::map<char, const unsigned int> m_charToDirectionConverter;
	FileHandler m_map;
	std::unique_ptr<RepTex>m_mapOnScreen;

	int m_numOfRotations = 0;
	int m_level = 1;

	//Board m_board;
};