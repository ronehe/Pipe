#include "Controller.h"
#include "Textures.h"
#pragma once

Controller::Controller()
	: m_gameWindow(sf::VideoMode(1200, 800), "Pipes",sf::Style::Close), m_background(Textures::instance().get_Textures(background))
{
	m_background.setTextureRect(sf::IntRect(100,1200 , 800,800 ));
	//m_background.setColor(sf::Color(0xFF, 0x63, 0x47));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::startGame() {
	sf::Event event;
	while (m_gameWindow.isOpen()) {
		m_gameWindow.clear();
		m_gameWindow.draw(m_background);

		m_board.drawBoard(m_gameWindow);
		m_gameWindow.display();

		while (m_gameWindow.pollEvent(event))
		{
			switch (event.type) {
			case::sf::Event::MouseButtonPressed:
				if (!(int(event.mouseMove.y / 100) > 7))
					if(event.mouseButton.button == sf::Mouse::Left)
						m_board.rotateTile(sf::Vector2i(int(event.mouseButton.y / 100), int(event.mouseButton.x / 100)), 90.f);
					else
						m_board.rotateTile(sf::Vector2i(int(event.mouseButton.y / 100), int(event.mouseButton.x / 100)), -90.f);
				break;
			case sf::Event::Closed:
				m_gameWindow.close();
				exit(EXIT_SUCCESS);
			};
		}
	}
}
