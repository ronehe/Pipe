#pragma once
#include "BasePipe.h"
#include "Textures.h"

class StraightPipe : public BasePipe {
public:
	

	StraightPipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertexLoc);//constarctor gets size and color
};
