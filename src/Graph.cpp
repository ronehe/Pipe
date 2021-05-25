#include "Graph.h"
#include <memory>
#include "Sink.h"

Graph::Graph(const sf::Vector2u& mapSize)
	:m_graphSize(mapSize) ,m_DestConnected(false){
	m_vertices.resize(mapSize.x);
	for (unsigned int i = 0; i < mapSize.x;i++) {
		m_vertices[i].resize(mapSize.y);
	}
}

//function for mainly initializing vertex at the construction of pipes
std::unique_ptr<Vertex>& Graph::getVertexAt(const sf::Vector2u& loc) {
	return m_vertices[loc.x][loc.y];
} 

//to add source vertices that will be used as entry points to the graph
void Graph::setSourceVertex(const sf::Vector2u& loc) {
	m_sourceVertices.push_back(m_vertices[loc.x][loc.y].get());
}

//for initializing for the first time edges
void Graph::initializeEdges() {
	for (auto row = 0; row < m_vertices.size(); row++) {
		for (auto col = 0; col < m_vertices[row].size(); col++) {
			updateVertexNeighbors( row,  col);
		}
	}
}

void Graph::rotate(const sf::Vector2u& posPipe, int direction) {
	m_vertices[posPipe.x][posPipe.y].get()->rotate(direction);
	updateAfterRotate(posPipe);
	BFS();
}
void Graph::updateAfterRotate(const sf::Vector2u& posPipe) {
	
	m_vertices[posPipe.x][posPipe.y].get()->removeNeighbors();
	updateVertexNeighbors(posPipe.x, posPipe.y);
	updateVertexNeighbors(posPipe.x-1, posPipe.y);
	updateVertexNeighbors(posPipe.x+1, posPipe.y);
	updateVertexNeighbors(posPipe.x, posPipe.y-1);
	updateVertexNeighbors(posPipe.x, posPipe.y+1);
}


void Graph::updateVertexNeighbors(int row, int col) {
	if (row<0 || row>m_graphSize.x-1 || col<0 || col>m_graphSize.y-1)
		return;

	if (row != 0) {

		if (m_vertices[row][col].get()->isPointingToDir(up_t) && m_vertices[row - 1][col].get()->isPointingToDir(down_t)) {
			m_vertices[row][col].get()->addNeighbor(m_vertices[row - 1][col].get());
		}
	}
	if (col != 0) {
		if (m_vertices[row][col].get()->isPointingToDir(left_t) && m_vertices[row][col - 1].get()->isPointingToDir(right_t)) {
			m_vertices[row][col].get()->addNeighbor(m_vertices[row][col - 1].get());
		}
	}
	if (col != m_graphSize.y - 1) {
		if (m_vertices[row][col].get()->isPointingToDir(right_t) && m_vertices[row][col + 1].get()->isPointingToDir(left_t)) {
			m_vertices[row][col].get()->addNeighbor(m_vertices[row][col + 1].get());
		}
	}
	if (row != m_graphSize.x - 1) {
		if (m_vertices[row][col].get()->isPointingToDir(down_t) && m_vertices[row + 1][col].get()->isPointingToDir(up_t)) {
			m_vertices[row][col].get()->addNeighbor(m_vertices[row + 1][col].get());
		}
	}
}

void Graph::setNoConnection() {
	m_DestConnected = false;
}


//The BFS was taken from https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

void Graph::BFS() {
	// Mark all the vertices as not visited
	std::vector<std::vector<bool>> visited;
	visited.resize(m_graphSize.x);
	for (int i = 0; i < m_graphSize.x; i++) {
		visited[i].resize(m_graphSize.y);
		for (int j = 0; j < m_graphSize.y; j++) {
			visited[i][j] = false;
		}
	}

	// Create a queue for BFS
	std::list<Vertex*> queue;

	// Mark the current node as visited and enqueue it
	//in case of more than one source vertex - tun through all of them
	for (auto s : m_sourceVertices) {
		auto curLoc = s->getloc();
		visited[curLoc.x][curLoc.y] = true;
		queue.push_back(s);

		// 'i' will be used to get all adjacent
		// vertices of a vertex
		std::list<Vertex*>::iterator i;

		while (!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			s = queue.front();
			m_vertices[curLoc.x][curLoc.y]->changeColor(sf::Color::White);

			queue.pop_front();

			// Get all adjacent vertices of the dequeued
			// vertex s. If a adjacent has not been visited,
			// then mark it visited and enqueue it
			for (auto i = s->getBeginNeighbor(); i != s->getEndNeighbor(); ++i)
			{
				curLoc = (*i)->getloc();
				if (!visited[curLoc.x][curLoc.y])
				{
					visited[curLoc.x][curLoc.y] = true;
					m_vertices[curLoc.x][curLoc.y]->changeColor(sf::Color::White);
					if (m_vertices[curLoc.x][curLoc.y].get()->vertexIsSrc()) {
						m_DestConnected = true;
						break;
					}
					queue.push_back(*i);
				}
			}
		}
	}
}

bool Graph::isDestConnected() {
	return m_DestConnected;
}
