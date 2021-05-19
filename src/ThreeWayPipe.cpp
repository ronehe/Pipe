#include "ThreeWayPipe.h"
ThreeWayPipe::ThreeWayPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)

	: BasePipe( loc,vertex)
{
	setTexture(Textures::instance().get_Textures(threeWayPipe_t));
}
