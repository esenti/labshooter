#ifndef __labshooter__SoundManager__
#define __labshooter__SoundManager__

#include <unordered_map>
#include <vector>

#include <SFML/Audio.hpp>

class SoundManager
{
private:
    static std::unordered_map<std::string, sf::Sound> Sounds;
    static std::vector<sf::SoundBuffer*> Buffers;
public:
    static void LoadSound(const std::string& name, const std::string& path);
    static void Play(const std::string& name);
};

#endif /* defined(__labshooter__SoundManager__) */
