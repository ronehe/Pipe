#pragma once
#include "Vertex.h"
#include <vector>
#include <list>
class Graph{
public:
	Graph(const sf::Vector2u& mapSize);
	std::shared_ptr<Vertex>& getVertexAt(const sf::Vector2u& loc);
	void setSourceVertex(const sf::Vector2u& loc);
	void initializeEdges();
	void updateVertexNeighboors(int row, int col);
	void rotate(const sf::Vector2u& posPipe, int direction);
	void uptadeAfterRotate(const sf::Vector2u& posPipe);//after rotation we need to set the neightbors of the current vetrex and the neighbors's neighbors  
	bool isDestConnected();


	void BFS() ;
private:
	std::vector<std::vector<std::shared_ptr<Vertex>>> m_vertices;
	std::vector<Vertex*> m_sourceVertices; //starting points for DFS/BFS
	const sf::Vector2u m_graphSize;
	bool m_DestConnected;
};