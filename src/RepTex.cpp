#include "RepTex.h"
#include "Textures.h"
#include "BasePipe.h"
RepTex::RepTex() {
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void RepTex::addPipe(BasePipe*, sf::Vector2u) {
	m_pipes[][]
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
