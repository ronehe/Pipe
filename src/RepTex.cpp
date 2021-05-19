#include "RepTex.h"
#include "Textures.h"
#include "BasePipe.h"
RepTex::RepTex(sf::Vector2u mapSize) 
{
	m_pipes.resize(mapSize.x);
	for (unsigned int i = 0; i < mapSize.x;i++) {
		m_pipes[i].resize(mapSize.y);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void RepTex::addPipe(BasePipe* curPipe) {
	auto loc = curPipe->getLoc();
	m_pipes[loc.x][loc.y] = curPipe;
}
//drawing the board on requested screen..
void RepTex::drawBoard(sf::RenderWindow& game_Window) {
	for (unsigned int i = 0; i < m_pipes.size(); i++) {
		for (unsigned int j = 0; j < m_pipes[i].size(); j++) {
			m_pipes[i][j]->drawPipe(game_Window);
		}
	}
}

//rotation function
void RepTex::rotatePipe(const sf::Vector2i &posPipe, float degrees) {
	
	m_pipes[posPipe.x][posPipe.y]->rotate(degrees);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
