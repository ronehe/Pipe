
#pragma once
#include "BasePipe.h"
#include "Textures.h"

class ThreeWayPipe : public BasePipe {
public:
	ThreeWayPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex);

};
