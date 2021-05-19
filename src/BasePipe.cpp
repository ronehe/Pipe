#include "BasePipe.h"

BasePipe::BasePipe( sf::Vector2f size, sf::Vector2f pos)
{
	m_pipe.setOrigin(HALF * size); //set the origin to be the middle
	m_pipe.setPosition(pos + HALF * size); 
	//m_tile.setColor(sf::Color(0x9A, 0xCD, 0x32));//green
	m_pipe.setColor(sf::Color(0xAD, 0xFF, 0x2F));//green

	m_pipe.setTextureRect(sf::IntRect(0, 0, 100, 100));
	//m_tile.setTexture(sf::Color)
}

void BasePipe::drawPipe(sf::RenderWindow& game_Window)const {
	game_Window.draw(m_pipe);
}

void BasePipe::setTexture(const sf::Texture& pic) {
	m_pipe.setTexture(pic);
}

void BasePipe::rotate(float degrees) {
	m_pipe.rotate(degrees);
}