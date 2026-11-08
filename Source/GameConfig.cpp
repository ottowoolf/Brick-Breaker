#include "GameConfig.h"

GameConfig::GameConfig()
    : windowSize({600.f, 800.f}), paddleSize({120.f, 20.f}), paddleSpeed(500.f), ballRadius(10.f), ballSpeed(250.f), ballSpawnInterval(3.f), musicVolume(70.f), BounceSoundVolume(10.f), startingLives(5)
{
}