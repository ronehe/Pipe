#include "Textures.h" 
#include "Macros.h"
#pragma once
Textures& Textures::instance() {
	static Textures all_S;
	return all_S;
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Textures::Textures() {
	sf::Texture pic;
	sf::Image im;
	im.loadFromFile("pieces.png");
	pic.loadFromFile("curvedPipe - Copy.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures,sf::Texture>(curvedPipe_t,pic));

	pic.loadFromFile("straightPipe - Copy.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(straightPipe_t, pic));

	pic.loadFromFile("bg2.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(background_t, pic));

	pic.loadFromFile("menu.png");
	pic.setSmooth(true);
	pic.setRepeated(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(menu_t, pic));

}
