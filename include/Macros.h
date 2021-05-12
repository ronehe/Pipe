#include <SFML/Graphics.hpp>
#pragma once
//const sf::Vector2f board_Start(560.f, 100.f);
const sf::Vector2f board_Start(0.f, 0.f);
//const sf::Vector2f toolSize(333.f, 333.f);
const float toolSize = 333.f;
const unsigned int different_Tools = 6;
auto const TOOLSCALE = sf::Vector2f(1.f / 3.3, 1.f / 3.3);

enum colors {
	white = 0,
	black = 1
};
enum pieces {
	king = 0,
	queen = 1,
	bishop = 2,
	knight = 3,
	rook = 4,
	pawn = 5
};
