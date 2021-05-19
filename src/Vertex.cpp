#include "Vertex.h"
Vertex::Vertex() {
	m_dir.insert(std::pair<const unsigned int, Vertex* >(TOP, nullptr));
	m_dir.insert(std::pair<const unsigned int, Vertex* >(BOT, nullptr));
	m_dir.insert(std::pair<const unsigned int, Vertex* >(LEFT, nullptr));
	m_dir.insert(std::pair<const unsigned int, Vertex* >(RIGHT, nullptr));

	m_pipe = 
}

//returns if both of the pointer are connected
bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const {
	return m_dir[dir] == pToPipe;
}
