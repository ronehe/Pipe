#include "Graph.h"
#include <memory>

Graph::Graph(const sf::Vector2u &mapSize) {
	m_vertices.resize(mapSize.x);
	for (unsigned int i = 0; i < mapSize.x;i++) {
		m_vertices[i].resize(mapSize.y);
	}
}

std::shared_ptr<Vertex>& Graph::getVertexAt(const sf::Vector2u& loc) {
	return m_vertices[loc.x][loc.y];
}