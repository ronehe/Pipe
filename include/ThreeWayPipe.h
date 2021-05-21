
#pragma once
#include "BasePipe.h"
#include "Textures.h"

class ThreeWayPipe : public BasePipe {
public:
	ThreeWayPipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex);

};
