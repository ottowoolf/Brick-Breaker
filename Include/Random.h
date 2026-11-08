#pragma once

#include <random>

class Random
{
private:
    std::random_device randomDevice_;
    std::mt19937 generator_;

public:
    Random();

    int GetRandomInt(int min, int max);
    float GetRandomFloat(float min, float max);
};

inline Random gRandom; // Global instance of Random class for easy access