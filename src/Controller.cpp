#include "Controller.h"
#include "Textures.h"
#include "CurvedPipe.h"
#pragma once

Controller::Controller()
	: m_gameWindow(SCREEN_SIZE, "Pipes",sf::Style::Close), m_background(Textures::instance().get_Textures(background_t)),
	m_bgMenu(Textures::instance().get_Textures(background_t)),
	m_mapOnScreen(m_map.get_Size())
{
	
	generateBackgrounds();
	
	updateDataStructures();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::generateBackgrounds() {
	m_background.setTextureRect(B_G_POS);
	m_bgMenu.setPosition(MENU_POS);
	m_bgMenu.setTextureRect(MENU_PLACEMENT_TEX);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::updateDataStructures() {
	sf::Vector2u loc;
	sf::Vector2f locOnWindow;
	sf::Texture curTex;
	char currentChar;
	auto size=m_map.get_Size();
	for (loc.x = 0; loc.x <size.x ; loc.x++) {
		for (loc.y = 0; loc.y < size.y; loc.y++) {
			currentChar = m_map.what_In_Location(loc);
			//auto curved = new CurvedPipe(PIPE_SIZE, loc);
			m_mapOnScreen.addPipe(currentChar,loc);
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

		m_mapOnScreen.drawBoard(m_gameWindow);
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
	auto size = m_map.get_Size();
	if (!(int(event.mouseButton.x / PIPE_TEXTURE_SIZE) > (size.y - 1)) && !(int(event.mouseButton.y / PIPE_TEXTURE_SIZE) > (size.x - 1))) {
		if (event.mouseButton.button == sf::Mouse::Left)
			m_mapOnScreen.rotatePipe(sf::Vector2i(int(event.mouseButton.y / PIPE_TEXTURE_SIZE), int(event.mouseButton.x / PIPE_TEXTURE_SIZE)), DEG90);
		else
			m_mapOnScreen.rotatePipe(sf::Vector2i(int(event.mouseButton.y / PIPE_TEXTURE_SIZE), int(event.mouseButton.x / PIPE_TEXTURE_SIZE)), -DEG90);
	}
}