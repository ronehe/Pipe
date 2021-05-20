#pragma once
#include "Macros.h"
class BasePipe;
class Vertex {
public:
	Vertex(BasePipe*);
	//bool Vertex::isThereEdge(const unsigned int dir, Vertex* pToPipe) const;
	void addNeighboors(Vertex* up, Vertex* right, Vertex* left, Vertex* down);
	void setDir(dir inpDir);
	dir getDir()const;
	void changeColor(const sf::Color& color);
private:
	BasePipe* m_pipe;
	
	Vertex* m_up;
	Vertex* m_right;
	Vertex* m_left;
	Vertex* m_down;
	
	dir m_dir;


};