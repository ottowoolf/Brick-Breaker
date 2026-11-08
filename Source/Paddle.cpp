#include "Paddle.h"
#include "GameConfig.h"
#include <algorithm>

Paddle::Paddle() : speed_(gGameConfig.paddleSpeed)
{

    paddle_.setSize({gGameConfig.windowSize.x * 0.3f, gGameConfig.windowSize.y * 0.03f});
    paddle_.setFillColor(sf::Color::Magenta);
    paddle_.setOrigin(paddle_.getGeometricCenter());
    paddle_.setPosition({gGameConfig.windowSize.x * 0.5f, gGameConfig.windowSize.y * 0.85f});
}

void Paddle::Draw(sf::RenderWindow &window) const
{
    window.draw(paddle_);
}

void Paddle::Move(float deltaTime)
{
    float moveDistance = speed_ * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        paddle_.move({moveDistance, 0.f});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        paddle_.move({-moveDistance, 0.f});
    }

    float paddleHalfWidth = paddle_.getSize().x * 0.5f;
    float clampedX = std::clamp(paddle_.getPosition().x, paddleHalfWidth, gGameConfig.windowSize.x - paddleHalfWidth);
    paddle_.setPosition({clampedX, paddle_.getPosition().y});
}

sf::FloatRect Paddle::GetGlobalBounds() const
{
    return paddle_.getGlobalBounds();
}