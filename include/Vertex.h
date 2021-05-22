#pragma once
#include "Macros.h"
#include <List>
#include <unordered_set>

class BasePipe;
class Vertex {
public:
	Vertex(BasePipe*);
	void addNeighbor(Vertex * neighbor);
	void setDir(const Dir& dir);
	void changeColor(const sf::Color& color);
	void rotate(int direction);
	bool isPointingToDir(Directions);
	void removeNeighbors();
	sf::Vector2u getloc()const;
	bool vertexIsSrc() const;
	std::unordered_set <Vertex*>::const_iterator getBeginNeighbor();
	std::unordered_set <Vertex*>::const_iterator getEndNeighbor();
private:
	BasePipe* m_pipe;
	std::unordered_set<Vertex*> m_neighbors;
	Dir m_dir; //boolean array if size 4 to indicate directions
};