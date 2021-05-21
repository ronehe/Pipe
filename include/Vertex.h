#pragma once
#include "Macros.h"
#include <List>
#include <unordered_set>

class BasePipe;
class Vertex {
public:
	Vertex(BasePipe*);
	//bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const;
	//void addNeighboors(Vertex* up, Vertex* right, Vertex* left, Vertex* down);
	void addNeighbor(Vertex * neighbor);
	void setDir(const Dir& dir);
	void changeColor(const sf::Color& color);
	void rotate(int direction);
	bool isPointingToDir( Directions);
	void removeNeighbors();
	sf::Vector2u getloc()const;
	//void removeNeighbor(Vertex* cur);
	std::unordered_set <Vertex*>::iterator getBeginNeighbor();
	std::unordered_set <Vertex*>::iterator getEndNeighbor();
private:
	BasePipe* m_pipe;
	std::unordered_set<Vertex*> m_neighbors;
	Dir m_dir;

};