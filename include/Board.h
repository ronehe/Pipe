#include "Tile.h"
#pragma once
class Board {


public:
	void draw_Board(sf::RenderWindow& game_Window)const;
	Tile& get_Tile(sf::Vector2i pos);

	Board();

private:


	std::vector<std::vector<Tile>> m_Board;
};