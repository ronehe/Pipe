#include "RepTex.h"
#include "Textures.h"
RepTex::RepTex() {
	//creates a basic tile table without texture
	m_tiles.resize(8);
	for (unsigned int i = 0; i < MAP_SIZE; i++) {
		for (unsigned int j = 0; j < MAP_SIZE; j++) {
			m_tiles[i].push_back(Tile(sf::Vector2f(100, 100), sf::Vector2f(board_Start.x + j * 100.f, board_Start.y + (i * 100.f))));
		}
	}	
	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void RepTex::addTextureToTile(sf::Vector2u loc, sf::Texture tex) {

	m_tiles[loc.x][loc.y].setTexture(tex);
}
//drawing the board on requested screen..
void RepTex::drawBoard(sf::RenderWindow& game_Window) {

	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			m_tiles[i][j].drawTile(game_Window);
		}
	}
}

//rotation function
void RepTex::rotateTile(const sf::Vector2i &posTile, float degrees) {
	m_tiles[posTile.x][posTile.y].rotate(degrees);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//returns  a tile in location on board ..
Tile& RepTex::getTile(sf::Vector2i pos) {
	return m_tiles[pos.x][pos.y];

	//return m_Board[int(pos.y/100)][int(pos.x/100)];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
