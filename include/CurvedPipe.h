#pragma once
#include "BasePipe.h"
#include "Textures.h"

class CurvedPipe : public BasePipe {
public:
	CurvedPipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex);

};