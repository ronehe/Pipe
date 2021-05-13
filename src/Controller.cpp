#include "Controller.h"
#include "Textures.h"
#pragma once

Controller::Controller()
	: m_gameWindow(sf::VideoMode(1200, 800), "Pipes")
{
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
				if (int(event.mouseMove.x) / 100 > 800)
					continue;
				else
					m_board.getTile(sf::Vector2i(int(event.mouseButton.y / 100), int(event.mouseButton.x / 100))).rotate();
				break;
			case sf::Event::Closed:
				m_gameWindow.close();
				exit(EXIT_SUCCESS);
			};
		}
	}
}




