#include "Vertex.h"
#include "BasePipe.h"
Vertex::Vertex(BasePipe* ptrPipe) {
	m_pipe = ptrPipe;
}
void Vertex::setDir(dir inpDir) {
	m_dir = inpDir;
}

void Vertex::addNeighboors(Vertex* up, Vertex* right, Vertex* left, Vertex *down ) {
	m_up =	up;
	m_down = down;
	m_left = left;
	m_right = right;

}
/*returns if both of the pointer are connected
bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const {

	return m_dir[dir] == pToPipe;
}
*/
