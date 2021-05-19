#include "RepTex.h"
#include "Textures.h"
#include "BasePipe.h"
#include "CurvedPipe.h"
#include "StraightPipe.h"
#include "ThreeWayPipe.h"

RepTex::RepTex(sf::Vector2u mapSize)
	: m_graph(mapSize)
{
	m_pipes.resize(mapSize.x);
	for (unsigned int i = 0; i < mapSize.x;i++) {
		m_pipes[i].resize(mapSize.y);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void RepTex::addPipe(char p,sf::Vector2u loc){
	std::shared_ptr<Vertex> pVertex;
	switch (p)
	{
	case 'A':
		m_pipes[loc.x][loc.y] = std::make_shared<CurvedPipe>(loc, m_graph.getVertexAt(loc));
		m_graph[loc.x + 1][loc.y]
		m_graph[loc.x][loc.y-1]
		m_graph.setConnections()
		break;
	case 'Y':
		m_pipes[loc.x][loc.y] = std::make_shared<StraightPipe>(loc);
		break;
	case 'S':
		m_pipes[loc.x][loc.y] = std::make_shared<ThreeWayPipe>(loc);
		break;
	default:
		break;
	}
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
