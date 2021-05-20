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

//to add source vertices that will be used as entry points to the graph
void Graph::setSourceVertex(const sf::Vector2u& loc) {
	m_sourceVertices.push_back(m_vertices[loc.x][loc.y]);
}

void Graph::updateEdges() {
	for (auto row = 0; row < m_vertices.size(); row++) {
		for (auto col = 0; col < m_vertices[row].size(); col++) {
			if(row != 0)
				if (m_vertices[row][col].get()->getDir().m_dir[0] && m_vertices[row - 1][col].get()->getDir().m_dir[2]) {
					m_vertices[row][col].get()->changeColor(sf::Color::Blue);
				}
				else 
					m_vertices[row][col].get()->changeColor(sf::Color::Green);
		}
	}
}