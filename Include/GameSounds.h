#pragma once
#include <SFML/Audio.hpp>

class GameSounds
{
private:
    sf::Music backgroundMusic_;

    sf::SoundBuffer bounceBuffer_;
    sf::Sound bounceSound_;

public:
    GameSounds();

    void PlayBounceSound();
    void RestartBackgroundMusic();
};