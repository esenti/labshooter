#include "SoundManager.h"

std::unordered_map<std::string, sf::Sound> SoundManager::Sounds;
std::vector<sf::SoundBuffer*> SoundManager::Buffers;

void SoundManager::LoadSound(const std::string& name, const std::string& path)
{
	sf::SoundBuffer* buffer = new sf::SoundBuffer;
	sf::Sound sound;
	buffer->loadFromFile(path);
	sound.setBuffer(*buffer);

	Buffers.push_back(buffer);
	Sounds[name] = sound;
}

void SoundManager::Play(const std::string& name)
{
	Sounds[name].play();
}
