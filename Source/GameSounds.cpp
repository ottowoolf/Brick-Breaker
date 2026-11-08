#include "GameSounds.h"
#include "GameConfig.h"

GameSounds::GameSounds() : backgroundMusic_("Content/Audio/CuriousFun.mp3"), bounceBuffer_("Content/Audio/BounceFX.wav"), bounceSound_(bounceBuffer_)
{
    backgroundMusic_.setLooping(true);
    backgroundMusic_.setVolume(gGameConfig.musicVolume);
    backgroundMusic_.play();
    bounceSound_.setVolume(gGameConfig.BounceSoundVolume);
}

void GameSounds::PlayBounceSound()
{
    bounceSound_.play();
}

void GameSounds::RestartBackgroundMusic()
{
    backgroundMusic_.stop();
    backgroundMusic_.play();
}