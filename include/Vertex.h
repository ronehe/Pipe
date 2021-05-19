#pragma once
#include "Macros.h"
class BasePipe;
class Vertex {
public:
	Vertex(BasePipe*);
	//bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const;
private:
	BasePipe* m_pipe;
	Connections m_connections;
};