#include "Fonts.h" 
#include <exception>


Fonts& Fonts::instance() {
	static Fonts all_S;
	return all_S;
}
void Fonts::loadFont(sf::Font& font, const std::string& fontName, GameFonts fontEnum){
	if (!font.loadFromFile(fontName)) throw std::exception((fontName +
							"does not exist, please check CMake or give a valid file name").data());
	m_gameFonts.insert(std::pair<GameFonts, sf::Font>(fontEnum, font));
	
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Fonts::Fonts() {
	sf::Font font;
	auto fontName = std::string();

	fontName = "FontOfTime.ttf";
	loadFont(font, fontName, PipedFont_t);
	m_gameFonts.insert(std::pair<GameFonts, sf::Font>(PipedFont_t, font));

	
}
