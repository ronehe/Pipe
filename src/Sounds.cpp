#include "Sounds.h" 
#include <exception>


Sounds& Sounds::instance() {
	static Sounds all_S;
	return all_S;
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Sounds::Sounds() {
	sf::SoundBuffer sound;
	if (!sound.loadFromFile("rotationSound.wav")) throw std::exception();
	m_gameSounds.insert(std::pair<GameSounds, sf::SoundBuffer>(rotation_t, sound));

	if (!sound.loadFromFile("cheers.wav")) throw std::exception();
	m_gameSounds.insert(std::pair<GameSounds, sf::SoundBuffer>(cheers_t, sound));
}
