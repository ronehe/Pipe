#include "Controller.h"
#include "Textures.h"
#include "Sounds.h"
#include "Fonts.h"
#include "Macros.h"
#include "CurvedPipe.h"

Controller::Controller()
	: m_gameWindow(SCREEN_SIZE, "Pipes", sf::Style::Close), m_background(Textures::instance().get_Textures(background_t)),
	m_bgMenu(Textures::instance().get_Textures(background_t))
{
	m_mapOnScreen = std::make_unique<RepTex>(m_map.get_Size());
	m_finishedLvlSound.setBuffer(Sounds::instance().get_Sounds(cheers_t));
	m_finishedLvlSound.setVolume(5);
	generateBackgrounds();
	
	updateDataStructures();

	m_timeText.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	m_timeText.setString("Time: ");
	m_timeText.setPosition(MENU_POS);
	m_timeText.setCharacterSize(50);
	m_timeText.setFillColor(sf::Color::Black);
	m_gameWindow.draw(m_timeText);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::newLvl() {
	//checking if there is a new lvl
	if (m_map.rebuild_Map()) {
		m_mapOnScreen.release();
		m_mapOnScreen = std::make_unique<RepTex>(m_map.get_Size());

		updateDataStructures();
	}
	
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::generateBackgrounds() {
	m_background.setTextureRect(B_G_POS);
	m_bgMenu.setPosition(MENU_POS);
	m_bgMenu.setTextureRect(MENU_PLACEMENT_TEX);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Controller::updateDataStructures() {
	
	m_mapOnScreen->initialize(m_map);
	m_clock.restart();

	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void Controller::startGame() {
	sf::Event event;
	while (m_gameWindow.isOpen()) {
		m_gameWindow.clear();
		m_gameWindow.draw(m_background);
		m_gameWindow.draw(m_bgMenu);
		m_timeText.setString("Time: " + std::to_string(int(m_clock.getElapsedTime().asSeconds())));
		m_gameWindow.draw(m_timeText);
		
		m_mapOnScreen->drawBoard(m_gameWindow);
		m_gameWindow.display();
		if (m_mapOnScreen->isLvlFinished()) {
			m_finishedLvlSound.play();
			newLvl();

		
		}
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
	auto dir = DEG90;
	if (!(int(event.mouseButton.x / PIPE_TEXTURE_SIZE) > (size.y - 1)) && !(int(event.mouseButton.y / PIPE_TEXTURE_SIZE) > (size.x - 1))) {
		if (event.mouseButton.button != sf::Mouse::Left)
			dir *= -1.f;
		m_mapOnScreen->rotatePipe(sf::Vector2u(int(event.mouseButton.y / PIPE_TEXTURE_SIZE), int(event.mouseButton.x / PIPE_TEXTURE_SIZE)), dir);

	}
}