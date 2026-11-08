#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{

private:
    sf::RectangleShape paddle_;
    float speed_; // Pixels per second

public:
    Paddle();

    void Draw(sf::RenderWindow &window) const;
    void Move(float deltaTime);

    sf::FloatRect GetGlobalBounds() const;
};
