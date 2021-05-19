#include "BasePipe.h"
#pragma once
class RepTex{
public:
	void addPipe(char p, sf::Vector2u loc);
	void drawBoard(sf::RenderWindow& game_Window);
	void rotatePipe(const sf::Vector2i& posTile, float);
	RepTex(sf::Vector2u mapSize);
private:
	std::vector<std::vector<std::shared_ptr<BasePipe>>> m_pipes;
	//Graph m_graph;
};