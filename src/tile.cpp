#include "Tile.h"

Tile::Tile(sf::Color cr, sf::Vector2f size, sf::Vector2f pos)
{
	m_tile.setPosition(pos);
	m_tile.setFillColor(cr);
	//m_Tile.setOutlineThickness(3);
	m_tile.setSize(size);
	m_tile.setOutlineColor(sf::Color::Black);

}

void Tile::draw_Tile(sf::RenderWindow& game_Window)const {
	game_Window.draw(m_tile);
}

bool operator==(const Tile& first, const Tile& second) {
	return (first.get_shape().getGlobalBounds().intersects
	(second.get_shape().getGlobalBounds()));
}
void Tile::setTexture(const sf::Texture& pic) {
	m_tile.setTexture(&pic);
}