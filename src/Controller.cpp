#include "Controller.h"
#include "Textures.h"
#pragma once

Controller::Controller()
	: m_Game_Window(sf::VideoMode(800, 800), "Chess")
{
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::start_Game() {
	Tile x(sf::Color::Red, sf::Vector2f(100.f, 100.f), sf::Vector2f(0.f, 0.f));
	int z, y;
	sf::Vector2i cursorPos;
	sf::Event event;
	while (m_Game_Window.isOpen()) {

		m_Game_Window.clear();

		m_Board.draw_Board(m_Game_Window);


		m_Game_Window.display();
		while (m_Game_Window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				m_Game_Window.close();
				exit(EXIT_SUCCESS);





			};


		}

	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//creating tool objects..

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//




