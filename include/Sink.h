#pragma once
#include "BasePipe.h"
#include "Textures.h"

class Sink : public BasePipe {
public:
	Sink(sf::Vector2u loc, std::unique_ptr<Vertex>& vertexLoc);//constarctor gets size and color
	void rotate(float) override;

};
