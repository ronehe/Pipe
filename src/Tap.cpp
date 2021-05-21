#include "Tap.h"
Tap::Tap(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{

	//get the direction from the vertex
	m_vertex->setDir(TAP_DIR);
	setTexture(Textures::instance().get_Textures(tap_t));
}
