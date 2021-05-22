#pragma once
#include "BasePipe.h"
#include "Graph.h"
#include"FileHandler.h"
class RepTex{
public:
	BasePipe* addPipe(char p, sf::Vector2u loc);
	void drawBoard(sf::RenderWindow& game_Window);
	void rotatePipe(const sf::Vector2u& posTile, float);
	RepTex(sf::Vector2u mapSize);
	void initialize(FileHandler &map);
	void resetColors();
	void shuffle();
	bool isLvlFinished();
	void resetSoundPipes();
private:
	std::vector<std::vector<std::unique_ptr<BasePipe>>> m_pipes;
	Graph m_graph;
};
