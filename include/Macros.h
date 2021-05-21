#include <SFML/Graphics.hpp>
#include <array>
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
enum Directions {
	up_t = 0,
	right_t,
	down_t,
	left_t

};
typedef std::array<bool, 4>Dir;

const Dir CURVED_DIR = { 0, 0, 1, 1 };
const Dir STRAIGHT_DIR = { 0, 1, 0, 1 };
const Dir THREE_DIR = { 0, 1, 1, 1 };
const Dir SINK_DIR = { 1, 1, 1, 1 };
const Dir TAP_DIR = { 0, 1, 0, 0 };
const Dir UNDEFINED_DIR = { 0, 0, 0, 0 };



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
const sf::Color UnonnectedPipeColor = sf::Color(0xAD, 0xFF, 0x2F);
//~~~~~~~~~~~~~~~~~~~~~~
