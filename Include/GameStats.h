#pragma once
#include <SFML/Graphics.hpp>

class GameStats
{
private:
    sf::Font font_;

    sf::Text scoreText_;
    sf::Text livesText_;
    sf::Text highScoreText_;

    int score_;
    int lives_;
    int highScore_;

public:
    GameStats();

    void Draw(sf::RenderWindow &window) const;

    // Setters

    void SetScore(int score);
    void SetLives(int lives);
    void SetHighScore(int highScore);

    // Getters

    int GetScore() const;
    int GetLives() const;
    int GetHighScore() const;

    // Reset the game stats to initial values

    void Reset();
};