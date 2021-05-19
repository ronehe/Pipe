#include "BasePipe.h"
#pragma once
class RepTex{
public:
	void addPipe(sf::Vector2u loc, const sf::Texture& tex);
	void drawBoard(sf::RenderWindow& game_Window);
	void rotatePipe(const sf::Vector2i& posTile, float);
	RepTex();
private:
	std::vector<std::vector<BasePipe>> m_pipes;
	Graph m_graph;
};