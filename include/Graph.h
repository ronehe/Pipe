#pragma once
#include "Vertex.h"
#include <vector>
#include <list>
class Graph{
public:
	Graph(const sf::Vector2u& mapSize);
	std::shared_ptr<Vertex>& getVertexAt(const sf::Vector2u& loc);
private:
	std::vector<std::vector<std::shared_ptr<Vertex>>> m_vertices;
};