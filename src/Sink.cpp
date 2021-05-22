#include "Sink.h"
Sink::Sink(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex)
	: BasePipe(loc,vertex)
{
	m_vertex->setDir(SINK_DIR);
	setTexture(Textures::instance().get_Textures(sink_t));
}
void Sink::rotate(float) {}

void Sink::setRotationSound() {
	m_rotationSound.setVolume(3);
	m_rotationSound.setBuffer(Sounds::instance().get_Sounds(SinkSound_t));
	m_connectionSound.setBuffer(Sounds::instance().get_Sounds(ConnectionSound_t));
	m_connectionSound.setVolume(3);
}

void Sink::playSound() {}
