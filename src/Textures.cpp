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
	//resizing the tools by color..
	m_Tool_Tex[white].resize(different_Tools);
	m_Tool_Tex[black].resize(different_Tools);


	for (unsigned int cr = 0; cr < 2; cr++) {
		for (unsigned int tl = king; tl < different_Tools; tl++) {
			//m_Tool_Tex[white][king].loadFromImage(im, sf::IntRect(0, 0, toolSize, toolSize));
			m_Tool_Tex[cr][tl].loadFromImage(im, sf::IntRect(toolSize * tl, toolSize * cr, toolSize, toolSize));
			m_Tool_Tex[cr][tl].setSmooth(true);
		}
	}




}
