#include "Vertex.h"
#include "BasePipe.h"
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


void Vertex::changeColor(const sf::Color& color) {
	m_pipe->changeColor(color);
}
void Vertex::addNeighbor(const std::shared_ptr<Vertex>& neighbor) {
	m_neighbors.push_back(neighbor);
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

	m_neighbors.clear();

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
