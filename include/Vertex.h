#pragma once
#include "Macros.h"
class Vertex {
public:
	Vertex();
	//bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const;
private:
	std::map<const unsigned int, Vertex*> m_dir; //directions of the edges
	//std::shared_ptr<BasePipe> m_pipe;
};