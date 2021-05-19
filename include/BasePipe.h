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
	BasePipe(   sf::Vector2u &loc);//constarctor gets size and color
	void setTexture(const sf::Texture& pic);
	virtual void rotate(float); //all do the same except sink
	 sf::Vector2u getLoc() const ;
	//~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	//~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	sf::Sprite m_pipe;
	const sf::Vector2u m_loc;
protected:
	std::shared_ptr<Vertex> m_vertex;
};