#include "BasePipe.h"

BasePipe::BasePipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex)
	:m_loc(loc)
{
	auto size = PIPE_SIZE;
	auto pos= sf::Vector2f(board_Start.x + loc.y * float(PIPE_TEXTURE_SIZE), board_Start.y + (loc.x * float(PIPE_TEXTURE_SIZE)));
	m_pipe.setOrigin(HALF * size); //set the origin to be the middle
	m_pipe.setPosition(pos + HALF * size); 
	m_pipe.setColor(sf::Color(0xAD, 0xFF, 0x2F));//green

	m_pipe.setTextureRect(sf::IntRect(0, 0, 100, 100));
	vertex = std::make_unique<Vertex>(this);
	m_vertex = vertex.get();
}

void BasePipe::setRotationSound() {
	m_rotationSound.setVolume(3);
	m_rotationSound.setBuffer(Sounds::instance().get_Sounds(rotation_t));
	m_connectionSound.setBuffer(Sounds::instance().get_Sounds(ConnectionSound_t));
	m_connectionSound.setVolume(3);
}
void BasePipe:: setVolume() {
	m_rotationSound.stop();
}

void BasePipe::drawPipe(sf::RenderWindow& game_Window)const {
	game_Window.draw(m_pipe);
}

void BasePipe::playSound() {
	m_connectionSound.stop();
	m_rotationSound.play();
}

void BasePipe::playConnectionSound() {
	m_rotationSound.stop();
	m_connectionSound.play();
}

void BasePipe::setTexture(const sf::Texture& pic) {
	m_pipe.setTexture(pic);
}

void BasePipe::rotate(float degrees) {
	m_pipe.rotate(degrees);
}

sf::Vector2u BasePipe::getLoc() const{
	return m_loc;
}

void BasePipe::changeColor(const sf::Color& color) {
	m_pipe.setColor(color);
}
