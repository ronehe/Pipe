#include "Tile.h"
#pragma once
class Board {


public:
	void drawBoard(sf::RenderWindow& game_Window);
	Tile& getTile(sf::Vector2i pos);

	Board();

private:


	std::vector<std::vector<Tile>> m_Board;
};