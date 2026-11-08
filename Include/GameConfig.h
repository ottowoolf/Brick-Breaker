#pragma once
#include <SFML/Graphics.hpp>

struct GameConfig
{
    sf::Vector2f windowSize;
    sf::Vector2f paddleSize;

    float paddleSpeed;
    float ballRadius;
    float ballSpeed;
    float ballSpawnInterval;
    float musicVolume;
    float BounceSoundVolume;
    int startingLives;

    GameConfig();
};

inline const GameConfig gGameConfig; // Global instance of GameConfig for easy access