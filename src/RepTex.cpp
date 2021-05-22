#include <cstdlib>
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
		m_pipes[loc.x][loc.y] = std::make_unique<CurvedPipe>(loc, m_graph.getVertexAt(loc));
		//setting the pointing direction of the vertex represnted by the texture
		break;
	case 'Y':
		m_pipes[loc.x][loc.y] = std::make_unique<StraightPipe>(loc, m_graph.getVertexAt(loc));
		break;
	case 'S':
		m_pipes[loc.x][loc.y] = std::make_unique<ThreeWayPipe>(loc, m_graph.getVertexAt(loc));
		break;
	case 'K':
		m_pipes[loc.x][loc.y] = std::make_unique<Sink>(loc, m_graph.getVertexAt(loc));
		break;
	case 'B':
		m_pipes[loc.x][loc.y] = std::make_unique<Tap>(loc, m_graph.getVertexAt(loc));
		m_graph.setSourceVertex(loc);
		break;

	default:
		throw std::invalid_argument(((std::string(1, p) + " is not a supprorted command, to see supported commands please go to README")).data());
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
			addPipe(currentChar, loc);
		}
	}

	m_graph.initializeEdges();
	shuffle();
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
	m_pipes[posPipe.x][posPipe.y]->playSound();
	
	m_pipes[posPipe.x][posPipe.y]->changeColor(UnonnectedPipeColor);
	m_graph.rotate(posPipe,int(degrees/std::abs(degrees)));
}

void RepTex::shuffle() {
	sf::Vector2u loc;
	int random;
	std::srand(std::time(nullptr));
	for(loc.x = 0; loc.x < m_pipes.size(); loc.x++){
		for(loc.y = 0; loc.y < m_pipes[loc.x].size(); loc.y++){
			random = std::rand() % 4;
			for (auto i = 0; i < random; i++)
				rotatePipe(loc, DEG90);
		}
	}
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
