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
	m_timeText.setString("Time: " + std::to_string(int(m_clock.getElapsedTime().asSeconds())));
	m_timeText.setPosition(MENU_POS);
	m_timeText.setCharacterSize(50);
	m_timeText.setFillColor(sf::Color::Black);

	m_rotationText.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	m_rotationText.setString("Rotations: " + std::to_string(m_numOfRotations));
	m_rotationText.setPosition(MENU_POS + sf::Vector2f(0, 100));
	m_rotationText.setCharacterSize(50);
	m_rotationText.setFillColor(sf::Color::Black);

	m_lvlText.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	m_lvlText.setString("Level: " + std::to_string(m_level));
	m_lvlText.setPosition(MENU_POS + sf::Vector2f(0, 200));
	m_lvlText.setCharacterSize(50);
	m_lvlText.setFillColor(sf::Color::Black);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
bool Controller::newLvl() {
	//checking if there is a new lvl
	if (m_map.rebuild_Map()) {
		m_mapOnScreen.release();
		m_mapOnScreen = std::make_unique<RepTex>(m_map.get_Size());
		updateDataStructures();
		m_level++;
		m_clock.restart();
		m_numOfRotations = 0;
		return true;
	}
	return false;
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
		m_rotationText.setString("Rotations: " + std::to_string(m_numOfRotations));
		m_lvlText.setString("Level: " + std::to_string(m_level));
		m_gameWindow.draw(m_timeText);
		m_gameWindow.draw(m_rotationText);
		m_gameWindow.draw(m_lvlText);
		
		m_mapOnScreen->drawBoard(m_gameWindow);
		m_gameWindow.display();
		if (m_mapOnScreen->isLvlFinished()) {
			m_gameWindow.display();
			m_finishedLvlSound.play();
			if (!newLvl()) { //if there isnt a new lvl
				printEndGameTex();
				m_gameWindow.close();
			}
			printNextLvlTex();
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
		m_numOfRotations++;
		if (event.mouseButton.button != sf::Mouse::Left)
			dir *= -1.f;
		m_mapOnScreen->rotatePipe(sf::Vector2u(int(event.mouseButton.y / PIPE_TEXTURE_SIZE), int(event.mouseButton.x / PIPE_TEXTURE_SIZE)), dir);
	}
}
void Controller::printEndGameTex() {
	m_clock.restart();
	while (m_clock.getElapsedTime().asSeconds() < 2);
	sf::Sprite game_over;
	game_over.setTexture(Textures::instance().get_Textures(gameFinished));
	m_gameWindow.draw(game_over);
	m_gameWindow.display();
	m_clock.restart();
	while (m_clock.getElapsedTime().asSeconds() < 5);
}
void Controller::printNextLvlTex()
{
	sf::Text solved;
	solved.setFont(Fonts::instance().get_Fonts(PipedFont_t));
	solved.setString("Well Done level solved");
	solved.setPosition(sf::Vector2f(100, 400));
	solved.setCharacterSize(100);
	solved.setFillColor(sf::Color::Red);
	solved.setOutlineThickness(1);
	m_gameWindow.draw(solved);
	m_gameWindow.display();
	m_clock.restart();
	while (m_clock.getElapsedTime().asSeconds() < 3);
}