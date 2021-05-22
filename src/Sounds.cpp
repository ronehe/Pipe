#include "Sounds.h" 
#include <exception>


Sounds& Sounds::instance() {
	static Sounds all_S;
	return all_S;
}

void Sounds::loadSound(sf::SoundBuffer& sound, const std::string& soundName,GameSounds soundsEnum) {
	if (!sound.loadFromFile(soundName)) throw std::exception((soundName +
							"does not exist, please check CMake or give a valid file name").data());
	m_gameSounds.insert(std::pair<GameSounds, sf::SoundBuffer>(soundsEnum, sound));

}

//set textures for all object in the game once
//all textures created here in a temporary variable, and are inserted into the map using copy constructors
Sounds::Sounds() {
	sf::SoundBuffer sound;
	auto soundName = std::string();

	soundName = "rotationSound.wav";
	loadSound(sound, soundName, rotation_t);

	soundName = "cheers.wav";
	loadSound(sound, soundName, cheers_t);

	soundName = "CantMove.wav";
	loadSound(sound, soundName, SinkSound_t);

	soundName = "connection.wav";
	loadSound(sound, soundName, ConnectionSound_t);
}
