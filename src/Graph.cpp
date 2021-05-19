#include "Graph.h"
#include <memory>

Graph::Graph() {
	m_vertices.resize(8);
	for (unsigned int i = 0; i < MAP_SIZE; i++) {
		for (unsigned int j = 0; j < MAP_SIZE; j++) {
			m_vertices[i].push_back(std::make_shared<Vertex>);
}