#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class Fonts{

	//--------------public--------functions-----------------------//
public:
	static Fonts& instance();
	//gets requested font from font member
	const sf::Font& get_Fonts(GameFonts key) { return (m_gameFonts[key]); }
	void loadFont(sf::Font& font, const std::string& fontName,GameFonts fontEnum);
	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
	Fonts();//constractor for static member
	std::map<GameFonts, sf::Font> m_gameFonts;
};
