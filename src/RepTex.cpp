#include "RepTex.h"
#include "Textures.h"
RepTex::RepTex() {
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void RepTex::addPipe(sf::Vector2u loc, const char c) {
	switch (c) {
	case 'A':
		m_pipes[loc.x][loc.y] = (BasePipe(sf::Vector2f(100, 100), sf::Vector2f(board_Start.x + loc.y * 100.f, board_Start.y + (loc.x * 100.f))));
	}
}
//drawing the board on requested screen..
void RepTex::drawBoard(sf::RenderWindow& game_Window) {
	for (unsigned int i = 0; i < 8; i++) {
		for (unsigned int j = 0; j < 8; j++) {
			m_pipes[i][j].drawPipe(game_Window);
		}
	}
}

//rotation function
void RepTex::rotatePipe(const sf::Vector2i &posPipe, float degrees) {
	m_pipes[posPipe.x][posPipe.y].rotate(degrees);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
