#include "Sink.h"
Sink::Sink(sf::Vector2u loc, std::shared_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	m_vertex.get()->setDir(dir(1, 1, 1, 1));

	setTexture(Textures::instance().get_Textures(sink_t));

}
void Sink::rotate(float) {

}

