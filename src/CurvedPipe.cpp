#include "CurvedPipe.h"
CurvedPipe::CurvedPipe(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)

	: BasePipe( loc, vertex)
{
	m_vertex.get()->setDir(CURVED_DIR);

	setTexture(Textures::instance().get_Textures(curvedPipe_t));
}
