#include "RepTex.h"
#include "Textures.h"
#include "BasePipe.h"
#include "CurvedPipe.h"
#include "StraightPipe.h"
#include "ThreeWayPipe.h"
#include "Sink.h"
#include "Tap.h"



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
	switch (p)
	{
	case 'A':
		m_pipes[loc.x][loc.y] = std::make_shared<CurvedPipe>(loc, m_graph.getVertexAt(loc));
		//setting the pointing direction of the vertex represnted by the texture
		break;
	case 'Y':
		m_pipes[loc.x][loc.y] = std::make_shared<StraightPipe>(loc, m_graph.getVertexAt(loc));
		break;
	case 'S':
		m_pipes[loc.x][loc.y] = std::make_shared<ThreeWayPipe>(loc, m_graph.getVertexAt(loc));
		break;
	case 'K':
		m_pipes[loc.x][loc.y] = std::make_shared<Sink>(loc, m_graph.getVertexAt(loc));
		break;
	case 'B':
		m_pipes[loc.x][loc.y] = std::make_shared<Tap>(loc, m_graph.getVertexAt(loc));
		m_graph.setSourceVertex(loc);
		break;

	default:
		break;
	}
}

void RepTex::initialize(FileHandler &map) {
	sf::Vector2u loc;
	auto size = map.get_Size();
	char currentChar;

	for (loc.x = 0; loc.x < size.x; loc.x++) {
		for (loc.y = 0; loc.y < size.y; loc.y++) {
			currentChar = map.what_In_Location(loc);
			//auto curved = new CurvedPipe(PIPE_SIZE, loc);
			addPipe(currentChar, loc);
		}
	}

	m_graph.initializeEdges();
	m_graph.BFS();
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
void RepTex::rotatePipe(const sf::Vector2u &posPipe, float degrees) {
	
	resetColors(); //for resetting colors in case of disconnection of pipes from tap
	m_pipes[posPipe.x][posPipe.y]->rotate(degrees);
	m_pipes[posPipe.x][posPipe.y]->changeColor(UnonnectedPipeColor);
	m_graph.rotate(posPipe,int(degrees/std::abs(degrees)));
	//m_graph.updateEdges();
	
}

void RepTex::resetColors() {
	for (auto& row : m_pipes) {
		for (auto& col : row) {
			col->changeColor(UnonnectedPipeColor);
		}
	}
}

bool RepTex::isLvlFinished() {
	return m_graph.isDestConnected();
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
