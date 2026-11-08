#pragma once
#include <SFML/Graphics.hpp>

class Ball
{

private:
    sf::CircleShape ball_;
    sf::Vector2f direction_;
    float speed_; // Pixels per second

public:
    Ball();

    void Draw(sf::RenderWindow &window) const;
    void Move(float deltaTime);
    void BounceOff();

    sf::FloatRect GetGlobalBounds() const;
    sf::Vector2f GetDirection() const;

    bool IsOutOfBounds() const;
};