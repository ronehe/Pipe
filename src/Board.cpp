#include "Board.h"


Board::Board() {

	unsigned int pos = 0;
	const sf::Color Current_Color[2] = { sf::Color(0xF5, 0xF5, 0xF5) ,sf::Color(0xD2, 0x69, 0x1E) };//easier to set color using it
	m_Board.resize(8);
	for (unsigned int i = 0; i < 8; i++) {
		//m_Board[i].resize(8);


		for (unsigned int j = 0; j < 8; j++) {
			if (j != 0)
				pos = !pos;//each col changes color but the first color in the new row is the last color in the last row

			m_Board[i].push_back(Tile(Current_Color[pos], sf::Vector2f(100, 100), sf::Vector2f(board_Start.x + j * 100.f, board_Start.y + (i * 100.f))));

		}

	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//drawing the board on requested screen..
void Board::draw_Board(sf::RenderWindow& game_Window)const {
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			m_Board[i][j].draw_Tile(game_Window);
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//returns  a tile in location on board ..
Tile& Board::get_Tile(sf::Vector2i pos) {
	return m_Board[pos.y][pos.x];

	//return m_Board[int(pos.y/100)][int(pos.x/100)];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
