#include "ThreeWayPipe.h"
ThreeWayPipe::ThreeWayPipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex)

	: BasePipe( loc,vertex)
{
	m_vertex->setDir(THREE_DIR);

	setTexture(Textures::instance().get_Textures(threeWayPipe_t));
}
