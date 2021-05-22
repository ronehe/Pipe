#include "Textures.h" 

Textures& Textures::instance() {
	static Textures all_So;
	return all_So;
}

void Textures::loadPic(sf::Texture& tex, const std::string& texName) {
	if (!tex.loadFromFile(texName)) throw std::exception((texName +
							" does not exist, please check CMake or give a valid file name\n").data());
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Textures::Textures() {
	sf::Texture pic;
	auto texName = std::string();

	texName = "CurvedPipe2.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures,sf::Texture>(curvedPipe_t,pic));

	texName = "straightPipe - Copy.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(straightPipe_t, pic));

	texName = "bg2.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(background_t, pic));

	texName = "menu.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	pic.setRepeated(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(menu_t, pic));
	
	texName = "threePipe.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(threeWayPipe_t, pic));
	
	texName = "k.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(sink_t, pic));

	texName = "b.png";
	loadPic(pic, texName);
	pic.setSmooth(true);
	m_pipeTex.insert(std::pair<pipeTextures, sf::Texture>(tap_t, pic));
}
