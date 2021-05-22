#include "Vertex.h"
#include "BasePipe.h"
#include "Sink.h"
Vertex::Vertex(BasePipe* ptrPipe) 
{
	m_dir = UNDEFINED_DIR;
	m_pipe = ptrPipe;
}
void Vertex::setDir(const Dir & dir) {
	m_dir = dir;
}
//checkes if the vertex pointing to the requested direction
bool Vertex::isPointingToDir(Directions cur) {
	return m_dir[cur];
}
sf::Vector2u Vertex::getloc()const {
	return m_pipe->getLoc();
}
std::unordered_set <Vertex*>::const_iterator Vertex::getBeginNeighbor(){
	return m_neighbors.cbegin();
}
std::unordered_set <Vertex*>::const_iterator Vertex::getEndNeighbor() {
	return m_neighbors.cend();
}
void Vertex::changeColor(const sf::Color& color) {
	m_pipe->changeColor(color);
}
void Vertex::addNeighbor( Vertex * neighbor) {
	m_pipe->playConnectionSound();
	m_neighbors.insert(neighbor);
}


void Vertex::rotate(int direction) {
	Dir cur = UNDEFINED_DIR;
	for (int i = 0; i < 4; i++) {
		if (m_dir[i] == true) {
			//sets the correct rotation using mudolo logic
			cur[(4 + ((i + direction) % 4)) % 4] = true;
		}
	}
	setDir(cur);
}
//resetting the 5 vertexes before updating them
void Vertex:: removeNeighbors() {
	for (auto it = m_neighbors.begin(); it != m_neighbors.end(); it++) {
		(*it)->m_neighbors.clear();
	}
	m_neighbors.clear();

}

bool Vertex::vertexIsSrc()const{
	return dynamic_cast<Sink*>(m_pipe);
}
