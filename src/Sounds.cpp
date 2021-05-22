#include "Sounds.h" 
#include <exception>


Sounds& Sounds::instance() {
	static Sounds all_S;
	return all_S;
}

void Sounds::loadSound(sf::SoundBuffer& sound, const std::string& soundName) {
	if (!sound.loadFromFile(soundName)) throw std::exception((soundName +
							"does not exist, please check CMake or give a valid file name").data());
}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Sounds::Sounds() {
	sf::SoundBuffer sound;
	auto soundName = std::string();

	soundName = "rotationSound.wav";
	loadSound(sound, soundName);
	m_gameSounds.insert(std::pair<GameSounds, sf::SoundBuffer>(rotation_t, sound));

	soundName = "cheers.wav";
	loadSound(sound, soundName);
	m_gameSounds.insert(std::pair<GameSounds, sf::SoundBuffer>(cheers_t, sound));
}
