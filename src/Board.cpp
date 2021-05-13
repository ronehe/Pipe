#include "Board.h"
#include "Textures.h"
#pragma once

Board::Board() {
	unsigned int pos = 0;
	const sf::Color CurrentColor[2] = { sf::Color(0xF5, 0xF5, 0xF5) ,sf::Color(0xD2, 0x69, 0x1E) };//easier to set color using it
	m_Board.resize(8);
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			if (j != 0)
				pos = !pos;//each col changes color but the first color in the new row is the last color in the last row

			m_Board[i].push_back(Tile(CurrentColor[pos], sf::Vector2f(100, 100), sf::Vector2f(board_Start.x + j * 100.f, board_Start.y + (i * 100.f))));
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//drawing the board on requested screen..
void Board::drawBoard(sf::RenderWindow& game_Window) {
	m_Board[1][1].setTexture(Textures::instance().get_Textures(straightPipe));
	m_Board[2][1].setTexture(Textures::instance().get_Textures(curvedPipe));
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			m_Board[i][j].drawTile(game_Window);
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//returns  a tile in location on board ..
Tile& Board::getTile(sf::Vector2i pos) {
	return m_Board[pos.x][pos.y];

	//return m_Board[int(pos.y/100)][int(pos.x/100)];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
