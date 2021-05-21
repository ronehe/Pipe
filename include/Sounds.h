#pragma once
#include <SFML/Audio.hpp>
#include "Macros.h"

class Sounds{

	//--------------public--------functions-----------------------//
public:
	static Sounds& instance();
	//gets requested sound from sound member
	const sf::SoundBuffer& get_Sounds(GameSounds key) { return (m_gameSounds[key]); }
	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
	Sounds();//constractor for static member
	//~Textures();
	std::map<enum GameSounds, sf::SoundBuffer> m_gameSounds;
};
