#include <SFML/Graphics.hpp>
#pragma once

//~~~~~~~~~Textures~~~~~~~~~~~~~
enum pipeTextures {
	curvedPipe_t = 0,
	straightPipe_t=1,
	background_t = 2,
	menu_t=3,
	threeWayPipe_t=4,
	sink_t =5,
	tap_t=6
};
//~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~graph~~~~~~~~~~~~~
struct Connections {
	bool m_connectionAbove;
	bool m_connectionBelow;
	bool m_connectionLeft;
	bool m_connectionRight;
};
struct dir {
	dir(bool left, bool right, bool up, bool down) {
		m_left = left;
		m_right = right;
		m_up = up;
		m_down = down;
	}
	dir() {
		m_left = 0;
		 m_right = 0;
		 m_up = 0;
		 m_down = 0;
	}
	bool m_left=0;
	bool m_right=0;
	bool m_up=0;
	bool m_down=0;
};


//~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~file handler~~~~~~~~~~~~~~
const unsigned int MAP_SIZE = 8;
//~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~Controller~~~~~~~~~~~~~~
const auto SCREEN_SIZE = sf::VideoMode(1200, 800);
const sf::Vector2f board_Start(0.f, 0.f);
const auto MENU_PLACEMENT_TEX = sf::IntRect(0, 800, 400, 800);
const auto MENU_POS = sf::Vector2f(800.f, 0.f);
const auto B_G_POS = sf::IntRect(100, 1200, 800, 800);
const auto DEG90 = 90.f;


//~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~tile~~~~~~~~~~~~~~
const int PIPE_TEXTURE_SIZE = 100;
const float HALF = float(1) / 2;
const sf::Vector2f PIPE_SIZE = sf::Vector2f(100, 100);
//~~~~~~~~~~~~~~~~~~~~~~
