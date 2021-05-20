#pragma once
#include "BasePipe.h"
#include "Textures.h"

class Tap : public BasePipe {
public:
	Tap(sf::Vector2u loc, std::shared_ptr<Vertex>& vertexLoc);//constarctor gets size and color

};
