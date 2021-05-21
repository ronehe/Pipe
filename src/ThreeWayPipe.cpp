#include "ThreeWayPipe.h"
ThreeWayPipe::ThreeWayPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)

	: BasePipe( loc,vertex)
{
	m_vertex.get()->setDir(THREE_DIR);

	setTexture(Textures::instance().get_Textures(threeWayPipe_t));
}
