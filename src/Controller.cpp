#include "Controller.h"
#include "Textures.h"
#include "CurvedPipe.h"
#pragma once

Controller::Controller()
	: m_gameWindow(SCREEN_SIZE, "Pipes",sf::Style::Close), m_background(Textures::instance().get_Textures(background_t)),
	m_bgMenu(Textures::instance().get_Textures(background_t))
{
	generateBackgrounds();
	createCharToTexCoverter();
	updateDataStructures();

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::createCharToTexCoverter() {
	m_charToTexConverter.insert(std::pair<char, pipeTextures>('A', curvedPipe_t));
	m_charToTexConverter.insert(std::pair<char, pipeTextures>('Y', straightPipe_t));
	m_charToTexConverter.insert(std::pair<char, pipeTextures>('S', threeWayPipe_t));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::generateBackgrounds() {
	m_background.setTextureRect(B_G_POS);
	m_bgMenu.setPosition(MENU_POS);
	m_bgMenu.setTextureRect(MENU_PLACEMENT_TEX);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::updateDataStructures() {
	sf::Vector2u loc;
	sf::Texture curTex;
	char currentChar;
	auto curved = CurvedPipe(l sf::Vector2f(100, 100), sf::Vector2f(board_Start.x + 0 * 100.f, board_Start.y + (0 * 100.f)));

	//for (loc.x = 0; loc.x < MAP_SIZE; loc.x++) {
		//for (loc.y = 0; loc.y < MAP_SIZE; loc.y++) {
			//currentChar = m_map.what_In_Location(loc);

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
	if (!(int(event.mouseMove.y / TILE_SIZE) > MAP_SIZE-1))
		if (event.mouseButton.button == sf::Mouse::Left)
			m_mapOnScreen.rotatePipe(sf::Vector2i(int(event.mouseButton.y / TILE_SIZE), int(event.mouseButton.x / TILE_SIZE)), DEG90);
		else
			m_mapOnScreen.rotatePipe(sf::Vector2i(int(event.mouseButton.y / TILE_SIZE), int(event.mouseButton.x / TILE_SIZE)), -DEG90);

}