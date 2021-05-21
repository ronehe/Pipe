#include "Graph.h"
#include <memory>

Graph::Graph(const sf::Vector2u& mapSize)
	:m_graphSize(mapSize) {
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

//for initializing for the first time edges
void Graph::initializeEdges() {
	for (auto row = 0; row < m_vertices.size(); row++) {
		for (auto col = 0; col < m_vertices[row].size(); col++) {
			if (row != 0) {
				if (m_vertices[row][col].get()->getDir().m_dir[0] && m_vertices[row - 1][col].get()->getDir().m_dir[2]) {
					m_vertices[row][col].get()->addNeighbor(m_vertices[row - 1][col]);
					m_vertices[row - 1][col].get()->addNeighbor(m_vertices[row][col]);
				}
			}
			if (col != 0) {
				if (m_vertices[row][col].get()->getDir().m_dir[1] && m_vertices[row][col - 1].get()->getDir().m_dir[3]) {
					m_vertices[row][col].get()->addNeighbor(m_vertices[row][col - 1]);
					m_vertices[row][col - 1].get()->addNeighbor(m_vertices[row][col]);
				}
			}
			if (col != m_graphSize.x - 1) {
				if (m_vertices[row][col].get()->getDir().m_dir[1] && m_vertices[row][col + 1].get()->getDir().m_dir[3]) {
					m_vertices[row][col].get()->addNeighbor(m_vertices[row][col + 1]);
					m_vertices[row][col + 1].get()->addNeighbor(m_vertices[row][col]);
				}
			}
			if (row != m_graphSize.y - 1) {
				if (m_vertices[row][col].get()->getDir().m_dir[3] && m_vertices[row + 1][col].get()->getDir().m_dir[1]) {
					m_vertices[row][col].get()->addNeighbor(m_vertices[row + 1][col]);
					m_vertices[row + 1][col].get()->addNeighbor(m_vertices[row + 1][col]);
				}
			}
		}
	}
}

	/*
void Graph::BFS() const{
	// Mark all the vertices as not visited
	std::vector<std::vector<bool>> visited;
	for (int i = 0; i < m_graphSize.x; i++)
		for(int j = 0; j < m_graphSize.y; j++)
			visited[i][j] = false;

	// Create a queue for BFS
	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	auto s = m_sourceVertices[0];
	visited[s.get()] = true;
	queue.push_back(s.get());

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
*/