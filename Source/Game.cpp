
#include "Game.h"
#include "Ball.h"
#include "GameConfig.h"

Game::Game() : window_(sf::VideoMode(sf::Vector2u(gGameConfig.windowSize)), "Brick Breaker")
{
    window_.setFramerateLimit(60);
}

bool Game::IsRunning()
{
    return window_.isOpen();
}

void Game::ProcessEvents()
{
    while (const auto event = window_.pollEvent())
    {

        if (event->is<sf::Event::Closed>())
        {
            window_.close();
        }
    }
}

void Game::Update()
{
    // Update game logic here

    // TODO: Implement delta time for smooth movement
    float deltaTime = clock_.restart().asSeconds();

    if (ballSpawnClock_.getElapsedTime().asSeconds() >= gGameConfig.ballSpawnInterval)
    {
        balls_.emplace_back();
        ballSpawnClock_.restart();
    }

    paddle_.Move(deltaTime);

    for (auto &ball : balls_)
    {
        ball.Move(deltaTime);
    }

    // Handle collisions
    HandleCollisions();

    // Check for game over condition
    if (gameStats_.GetLives() <= 0)
    {
        Restart();
    }
}

void Game::Render()
{
    window_.clear();

    // Draw background
    background_.Draw(window_);

    // Render game objects here
    paddle_.Draw(window_);

    for (const auto &ball : balls_)
    {
        ball.Draw(window_);
    }

    gameStats_.Draw(window_);

    // Display the rendered frame
    window_.display();
}

void Game::HandleCollisions()
{
    // Check for collision between ball and paddle
    sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();

    for (auto &ball : balls_)
    {
        sf::FloatRect ballBounds = ball.GetGlobalBounds();

        bool isColliding = ballBounds.findIntersection(paddleBounds).has_value();

        if (isColliding && ball.GetDirection().y > 0)
        {
            ball.BounceOff();
            gameStats_.SetScore(gameStats_.GetScore() + 1);
            gameSounds_.PlayBounceSound();
        }
    }

    // Remove balls that are out of bounds
    std::size_t missedBalls = std::erase_if(balls_, [](const Ball &ball)
                                            { return ball.IsOutOfBounds(); });

    if (missedBalls > 0)
    {
        gameStats_.SetLives(gameStats_.GetLives() - missedBalls);
    }
}

void Game::Restart()
{
    balls_.clear();
    ballSpawnClock_.restart();
    gameStats_.Reset();
    gameSounds_.RestartBackgroundMusic();
}