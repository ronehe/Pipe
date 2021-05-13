#include "Controller.h"
#include "Textures.h"
#pragma once

Controller::Controller()
	: m_gameWindow(sf::VideoMode(1200, 800), "Pipes"), m_background(Textures::instance().get_Textures(background))
{
	m_gameWindow.draw(m_background);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::startGame() {
	sf::Event event;
	while (m_gameWindow.isOpen()) {
		m_gameWindow.clear();
		m_board.drawBoard(m_gameWindow);
		m_gameWindow.display();

		while (m_gameWindow.pollEvent(event))
		{
			switch (event.type) {
			case::sf::Event::MouseButtonPressed:
				if (!(int(event.mouseMove.y / 100) > 7))
					m_board.rotateTile(sf::Vector2i(int(event.mouseButton.y / 100), int(event.mouseButton.x / 100)));
				break;
			case sf::Event::Closed:
				m_gameWindow.close();
				exit(EXIT_SUCCESS);
			};
		}
	}
}
