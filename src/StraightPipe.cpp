#include "StraightPipe.h"
StraightPipe::StraightPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	setTexture(Textures::instance().get_Textures(straightPipe_t));

}
