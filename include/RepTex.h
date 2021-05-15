#include "Tile.h"
#pragma once
class RepTex{


public:
	void drawBoard(sf::RenderWindow& game_Window);
	Tile& getTile(sf::Vector2i pos);
	void rotateTile(const sf::Vector2i& posTile, float);
	RepTex();
private:
	std::vector<std::vector<Tile>> m_tiles;
};