#include "CurvedPipe.h"
CurvedPipe::CurvedPipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex)
	: BasePipe( loc, vertex)
{
	m_vertex->setDir(CURVED_DIR);

	setTexture(Textures::instance().get_Textures(curvedPipe_t));
}
