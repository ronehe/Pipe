#include "ThreeWayPipe.h"
ThreeWayPipe::ThreeWayPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)

	: BasePipe( loc,vertex)
{
	m_vertex.get()->setDir(dir(1, 1, 0, 1));

	setTexture(Textures::instance().get_Textures(threeWayPipe_t));
}
