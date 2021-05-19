#include <vector>
#include <string> 
#include<iostream>
#include <stdlib.h>
#include "Macros.h"
#include <Vertex.h>
#pragma once

class BasePipe{
public:
	void drawPipe(sf::RenderWindow& game_Window)const;
	BasePipe( sf::Vector2f size, const sf::Vector2f &loc);//constarctor gets size and color
	void setTexture(const sf::Texture& pic);
	virtual void rotate(float); //all do the same except sink
	//~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	//~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	sf::Sprite m_pipe;
	std::shared_ptr<Vertex> m_vertex;
	const sf::Vector2u m_loc;
};