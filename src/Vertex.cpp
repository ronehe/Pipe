#include "Vertex.h"
#include "BasePipe.h"
Vertex::Vertex(BasePipe* ptrPipe) {
	m_pipe = ptrPipe;
}

//returns if both of the pointer are connected
bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const {
	return m_dir[dir] == pToPipe;
}
