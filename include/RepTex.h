#include "BasePipe.h"
#include "Graph.h"
#include"FileHandler.h"
#pragma once
class RepTex{
public:
	void addPipe(char p, sf::Vector2u loc);
	void drawBoard(sf::RenderWindow& game_Window);
	void rotatePipe(const sf::Vector2u& posTile, float);
	RepTex(sf::Vector2u mapSize);
	void initialize(FileHandler &map);
	void resetColors();
	bool isLvlFinished();
private:
	std::vector<std::vector<std::unique_ptr<BasePipe>>> m_pipes;
	Graph m_graph;
};
