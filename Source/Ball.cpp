
#include "Ball.h"
#include "Random.h"
#include "GameConfig.h"

Ball::Ball() : speed_(gGameConfig.ballSpeed), ball_(gGameConfig.ballRadius)
{
    ball_.setFillColor(sf::Color::Yellow);
    ball_.setOrigin(ball_.getGeometricCenter());
    ball_.setPosition({gGameConfig.windowSize.x * 0.5f, gGameConfig.windowSize.y * 0.25f});

    direction_ = {1, sf::degrees(gRandom.GetRandomFloat(0, 360))};
}

void Ball::Draw(sf::RenderWindow &window) const
{
    window.draw(ball_);
}

void Ball::Move(float deltaTime)
{
    sf::Vector2f lastPosition = ball_.getPosition();
    ball_.move(direction_ * speed_ * deltaTime);

    if (ball_.getPosition().y < ball_.getRadius())
    {
        ball_.setPosition(lastPosition);
        direction_.y *= -1; // Reverse vertical direction
    }

    if (ball_.getPosition().x < ball_.getRadius() || ball_.getPosition().x > gGameConfig.windowSize.x - ball_.getRadius())
    {
        ball_.setPosition(lastPosition);
        direction_.x *= -1; // Reverse horizontal direction
    }
}

void Ball::BounceOff()
{
    direction_.y *= -1; // Reverse vertical direction
}

sf::FloatRect Ball::GetGlobalBounds() const
{
    return ball_.getGlobalBounds();
}

sf::Vector2f Ball::GetDirection() const
{
    return direction_;
}

bool Ball::IsOutOfBounds() const
{
    return ball_.getPosition().y - ball_.getRadius() > gGameConfig.windowSize.y;
}