#pragma once
#include "Macros.h"
#include <List>
class BasePipe;
class Vertex {
public:
	Vertex(BasePipe*);
	//bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const;
	//void addNeighboors(Vertex* up, Vertex* right, Vertex* left, Vertex* down);
	void addNeighbor(const std::shared_ptr<Vertex>& neighbor);
	void setDir(const Dir& dir);
	void changeColor(const sf::Color& color);
	void rotate(int direction);
	bool isPointingToDir( Directions);
	void removeNeighbors();
	//void removeNeighbor(Vertex* cur);

private:
	BasePipe* m_pipe;

	std::list<std::shared_ptr<Vertex>> m_neighbors;
	Vertex* m_up;
	Vertex* m_right;
	Vertex* m_left;
	Vertex* m_down;
	
	 Dir m_dir;


};