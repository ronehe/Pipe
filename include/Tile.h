#include <vector>
#include <string> 
#include<iostream>
#include <stdlib.h>
#include "Macros.h"
#pragma once

class Tile {
public:
	void draw_Tile(sf::RenderWindow& game_Window)const;
	Tile(sf::Color cr, sf::Vector2f size, sf::Vector2f pos);//constarctor gets size and color
	sf::RectangleShape get_shape()const { return  m_Tile; };
	bool contains(sf::Vector2f loc)const { return m_Tile.getGlobalBounds().contains(loc); }

	//~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:

	//~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

private:

	sf::RectangleShape m_Tile;
};

bool operator==(const Tile& first, const Tile& second);