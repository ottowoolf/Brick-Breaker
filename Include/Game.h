#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Paddle.h"
#include "Ball.h"
#include "GameStats.h"
#include "GameSounds.h"
#include "Background.h"

class Game
{

private:
    sf::RenderWindow window_;
    sf::Clock clock_; // For delta time calculation

    Paddle paddle_;
    std::vector<Ball> balls_;
    sf::Clock ballSpawnClock_; // For spawning balls at intervals

    GameStats gameStats_;
    GameSounds gameSounds_;

    Background background_;

public:
    Game();

    bool IsRunning();

    void ProcessEvents();
    void Update();
    void Render();

private:
    void HandleCollisions();
    void Restart();
};