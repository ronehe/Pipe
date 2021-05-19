
#include "StraightPipe.h"
StraightPipe::StraightPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)
	: BasePipe(loc)
{
	setTexture(Textures::instance().get_Textures(straightPipe_t));
	vertex = std::make_shared<Vertex>(this);
	m_vertex = vertex;
}
