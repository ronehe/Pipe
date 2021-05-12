#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#pragma once

class Textures {

	//--------------public--------functions-----------------------//
public:
	static Textures& instance();
	//gets requested sound from sound member
	const sf::Texture& get_Textures(unsigned int cr, unsigned int type_E) { return (m_Tool_Tex[cr][type_E]); }
	//const sf::Font& get_Font(){ return m_Font; }
	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
	Textures();//constractor for static member
	//~Textures();
	std::vector<sf::Texture> m_Tool_Tex[2];

};
