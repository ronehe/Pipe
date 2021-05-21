#include "Tap.h"
Tap::Tap(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	m_vertex.get()->setDir(TAP_DIR);
	setTexture(Textures::instance().get_Textures(tap_t));
}
