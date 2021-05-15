#include "Controller.h"
#include "Textures.h"
#pragma once

Controller::Controller()
	: m_gameWindow(SCREEN_SIZE, "Pipes",sf::Style::Close), m_background(Textures::instance().get_Textures(background_t)),
	m_bgMenu(Textures::instance().get_Textures(background_t))
{
	generateBackgrounds();
	//updateDataStructures();


}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::generateBackgrounds() {
	m_background.setTextureRect(B_G_POS);
	m_bgMenu.setPosition(MENU_POS);
	m_bgMenu.setTextureRect(MENU_PLACEMENT_TEX);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::updateDataStructures() {
	for (auto i = 0; i < MAP_SIZE; i++) {
		for (auto j = 0; j < MAP_SIZE; j++) {
		

		
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void Controller::startGame() {
	sf::Event event;
	while (m_gameWindow.isOpen()) {
		m_gameWindow.clear();
		m_gameWindow.draw(m_background);
		m_gameWindow.draw(m_bgMenu);

		m_board.drawBoard(m_gameWindow);
		m_gameWindow.display();

		while (m_gameWindow.pollEvent(event))
		{
			switch (event.type) {
			case::sf::Event::MouseButtonPressed:
				rotate( event);
				break;
			case sf::Event::Closed:
				m_gameWindow.close();
				exit(EXIT_SUCCESS);
			};
		}
	}
}
void Controller::rotate(sf::Event event) {
	if (!(int(event.mouseMove.y / TILE_SIZE) > MAP_SIZE-1))
		if (event.mouseButton.button == sf::Mouse::Left)
			m_board.rotateTile(sf::Vector2i(int(event.mouseButton.y / TILE_SIZE), int(event.mouseButton.x / TILE_SIZE)), DEG90);
		else
			m_board.rotateTile(sf::Vector2i(int(event.mouseButton.y / TILE_SIZE), int(event.mouseButton.x / TILE_SIZE)), -DEG90);

}