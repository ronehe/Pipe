#include <SFML/Graphics.hpp>
#pragma once
const sf::Vector2f board_Start(0.f, 0.f);
enum pipeTextures {
	curvedPipe_t = 0,
	straightPipe_t=1,
	background_t = 2,
	menu_t=3
};

const int TOP = 1;
const int BOT = -1;
const int LEFT = 2;
const int RIGHT = -2;


const float HALF = float(1) / 2;
