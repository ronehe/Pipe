#include <SFML/Graphics.hpp>
#pragma once

//~~~~~~~~~Textures~~~~~~~~~~~~~
enum pipeTextures {
	curvedPipe_t = 0,
	straightPipe_t=1,
	background_t = 2,
	menu_t=3,
	threeWayPipe_t=4
};
//~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~graph~~~~~~~~~~~~~
const int TOP = 1;
const int BOT = -1;
const int LEFT = 2;
const int RIGHT = -2;
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
const int PIPE_SIZE = 100;
const float HALF = float(1) / 2;
//~~~~~~~~~~~~~~~~~~~~~~
