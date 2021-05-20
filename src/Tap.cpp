#include "Tap.h"
Tap::Tap(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	m_vertex.get()->setDir(dir(0, 1, 0, 0));
	setTexture(Textures::instance().get_Textures(tap_t));
}
