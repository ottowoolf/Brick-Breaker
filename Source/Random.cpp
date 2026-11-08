#include "Random.h"

Random::Random() : generator_(randomDevice_())
{
}

int Random::GetRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator_);
}

float Random::GetRandomFloat(float min, float max)
{
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator_);
}