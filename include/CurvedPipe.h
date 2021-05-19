#pragma once
#include "BasePipe.h"
#include "Textures.h"

class CurvedPipe : public BasePipe {
public:
	CurvedPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex);

};