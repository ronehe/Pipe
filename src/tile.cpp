#include "Tile.h"

Tile::Tile( sf::Vector2f size, sf::Vector2f pos)
{
	m_tile.setOrigin(HALF * size); //set the origin to be the middle
	m_tile.setPosition(pos + HALF * size); 
	//m_tile.setColor(sf::Color(0x9A, 0xCD, 0x32));//green
	m_tile.setColor(sf::Color(0xAD, 0xFF, 0x2F));//green
	m_tile.setTextureRect(sf::IntRect(0, 0, 100, 100));
	//m_tile.setTexture(sf::Color)
}

void Tile::drawTile(sf::RenderWindow& game_Window)const {
	game_Window.draw(m_tile);
}

bool operator==(const Tile& first, const Tile& second) {
	return (first.getShape().getGlobalBounds().intersects
	(second.getShape().getGlobalBounds()));
}
void Tile::setTexture(const sf::Texture& pic) {
	m_tile.setTexture(pic);
}

void Tile::rotate(float degrees) {
	m_tile.rotate(degrees);
}