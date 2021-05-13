#include <vector>
#include <string> 
#include<iostream>
#include <stdlib.h>
#include "Macros.h"
#pragma once

class Tile {
public:
	void drawTile(sf::RenderWindow& game_Window)const;
	Tile(sf::Color cr, sf::Vector2f size, sf::Vector2f pos);//constarctor gets size and color
	sf::RectangleShape getShape()const { return  m_tile; };
	bool contains(sf::Vector2f loc)const { return m_tile.getGlobalBounds().contains(loc); }
	void setTexture(const sf::Texture & pic);
	void rotate();
	//~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	//~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	sf::RectangleShape m_tile;
};
bool operator==(const Tile& first, const Tile& second);