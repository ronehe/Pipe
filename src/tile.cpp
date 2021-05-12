#include "Tile.h"

Tile::Tile(sf::Color cr, sf::Vector2f size, sf::Vector2f pos)
{
	m_Tile.setPosition(pos);
	m_Tile.setFillColor(cr);
	//m_Tile.setOutlineThickness(3);
	m_Tile.setSize(size);
	m_Tile.setOutlineColor(sf::Color::Black);

}

void Tile::draw_Tile(sf::RenderWindow& game_Window)const {
	game_Window.draw(m_Tile);
}

bool operator==(const Tile& first, const Tile& second) {
	return (first.get_shape().getGlobalBounds().intersects
	(second.get_shape().getGlobalBounds()));
}