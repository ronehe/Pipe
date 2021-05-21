#include "Sink.h"
Sink::Sink(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	m_vertex.get()->setDir(SINK_DIR);

	setTexture(Textures::instance().get_Textures(sink_t));

}
void Sink::rotate(float) {

}

