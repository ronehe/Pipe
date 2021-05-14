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

	pic.loadFromFile("curvedPipe - Copy.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures,sf::Texture>(curvedPipe,pic));

	pic.loadFromFile("straightPipe - Copy.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(straightPipe, pic));

	pic.loadFromFile("bg2.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(background, pic));
}
