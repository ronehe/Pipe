#include "Sink.h"
Sink::Sink(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	m_vertex->setDir(SINK_DIR);

	setTexture(Textures::instance().get_Textures(sink_t));

}
void Sink::rotate(float) {

}

