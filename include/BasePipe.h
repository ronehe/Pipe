#pragma once
#include <vector>
#include <string> 
#include<iostream>
#include <stdlib.h>
#include "Macros.h"
#include <Vertex.h>
#include "Sounds.h"

class BasePipe{
public:
	void drawPipe(sf::RenderWindow& game_Window)const;
	//BasePipe(   sf::Vector2u &loc);//constarctor gets size and color
	BasePipe(sf::Vector2u loc, std::unique_ptr<Vertex>& vertex);//constarctor gets size and color
	void setTexture(const sf::Texture& pic);
	virtual void rotate(float); //all do the same except sink
	 sf::Vector2u getLoc() const ;
	 void changeColor(const sf::Color&);
	 virtual void playSound();
	 virtual void playConnectionSound();
	 virtual void setRotationSound();
	 virtual void setVolume();

	 
	 virtual ~BasePipe() {} 
	//~~~~~~~~~~~~~~~~~~~private functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	//~~~~~~~~~~~~~~~~~~~private members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:
	sf::Sprite m_pipe;
	const sf::Vector2u m_loc;
protected:
	Vertex* m_vertex;
	sf::Sound m_rotationSound;
	sf::Sound m_connectionSound;
};