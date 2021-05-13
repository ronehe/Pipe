#include "Textures.h" 
#include "Macros.h"
#pragma once
Textures& Textures::instance() {
	static Textures  all_S;
	return all_S;
}
//set textures for all object in the game once
Textures::Textures() {
	//m_Font.loadFromFile("Love America.ttf");//setting one font
	sf::Texture pic;
	sf::Image im;
	im.loadFromFile("pieces.png");
	pic.loadFromFile("curvedPipe - Copy.png");
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures,sf::Texture>(curvedPipe,pic));

	pic.loadFromFile("straightPipe - Copy.png");
	pic.setSmooth(true);
	
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(straightPipe, pic));

	pic.loadFromFile("background.jpeg");
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(background, pic));






}
