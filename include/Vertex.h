#pragma once
#include "Macros.h"
class Vertex {

public :
	Vertex();

private:
	std::map<const unsigned int, Vertex *>m_dir; //directions of the edges


};