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
std::unordered_set <Vertex*>::iterator Vertex::getBeginNeighbor(){
	return m_neighbors.begin();
}
std::unordered_set <Vertex*>::iterator Vertex::getEndNeighbor() {
	return m_neighbors.end();
}
void Vertex::changeColor(const sf::Color& color) {
	m_pipe->changeColor(color);
}
void Vertex::addNeighbor( Vertex * neighbor) {
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

bool Vertex::pipeIsSink()const{
	return dynamic_cast<Sink*>(m_pipe);
}
/*
* smart removing function maybe used later on 
void Vertex ::removeNeighbor(Vertex*cur) {
	auto it = std::find(m_neighbors.begin(), m_neighbors.end(), cur);
	if (it!= m_neighbors.end()) {
		m_neighbors.erase(it);
	}

}
*/
/*returns if both of the pointer are connected
bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const {

	return m_dir[dir] == pToPipe;
}
*/
