#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Fonts{

	//--------------public--------functions-----------------------//
public:
	static Fonts& instance();
	//gets requested sound from sound member
	const sf::Font& get_Fonts(GameFonts key) { return (m_gameFonts[key]); }
	void loadFont(sf::Font& sound, const std::string& fontName);
	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
	Fonts();//constractor for static member
	std::map<GameFonts, sf::Font> m_gameFonts;
};
