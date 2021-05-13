#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Macros.h"
#pragma once

class Textures {

	//--------------public--------functions-----------------------//
public:
	static Textures& instance();
	//gets requested sound from sound member
	const sf::Texture& get_Textures(pipeTextures key) { return (m_pipeTex[key]); }
	//const sf::Font& get_Font(){ return m_Font; }
	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
	Textures();//constractor for static member
	//~Textures();
	std::map<enum pipeTextures, sf::Texture> m_pipeTex;

};
