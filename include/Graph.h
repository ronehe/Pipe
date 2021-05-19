#pragma once
#include "Vertex.h"
#include <vector>
#include <list>
class Graph{
public:
	//Graph();
private:
	std::vector<std::vector<std::shared_ptr<Vertex>>> m_vertices;
};