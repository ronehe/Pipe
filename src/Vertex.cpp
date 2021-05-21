#include "Vertex.h"
#include "BasePipe.h"
Vertex::Vertex(BasePipe* ptrPipe) {
	m_pipe = ptrPipe;
}
void Vertex::setDir(dir inpDir) {
	m_dir = inpDir;
}


/*
void Vertex::addNeighboors(Vertex* up, Vertex* right, Vertex* left, Vertex *down ) {
	m_up =	up;
	m_down = down;
	m_left = left;
	m_right = right;
}
*/

dir Vertex::getDir()const {
	return m_dir;
}

void Vertex::changeColor(const sf::Color& color) {
	m_pipe->changeColor(color);
}
void Vertex::addNeighbor(const std::shared_ptr<Vertex>& neighbor) {
	m_neighbors.push_back(neighbor);
}

/*returns if both of the pointer are connected
bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const {

	return m_dir[dir] == pToPipe;
}
*/
