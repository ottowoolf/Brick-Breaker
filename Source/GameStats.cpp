#include "GameStats.h"
#include "GameConfig.h"
#include <fstream>

GameStats::GameStats() : font_("Content/Audiowide.ttf"), scoreText_(font_), livesText_(font_), highScoreText_(font_)
{
    scoreText_.setCharacterSize(24);
    scoreText_.setFillColor(sf::Color::Yellow);
    scoreText_.setPosition({10.f, 10.f});
    SetScore(0);

    livesText_.setCharacterSize(24);
    livesText_.setFillColor(sf::Color::Red);
    livesText_.setPosition({10.f, 40.f});
    SetLives(gGameConfig.startingLives);

    highScoreText_.setCharacterSize(24);
    highScoreText_.setFillColor(sf::Color::Green);
    highScoreText_.setPosition({10.f, 70.f});

    // Load the high score from high score file

    if (std::ifstream file{"Highscores.txt"})
    {
        file >> highScore_;
    }
    else
    {
        SetHighScore(0);
    }

    SetHighScore(highScore_);
}

void GameStats::Draw(sf::RenderWindow &window) const
{
    window.draw(scoreText_);
    window.draw(livesText_);
    window.draw(highScoreText_);
}

void GameStats::SetScore(int score)
{
    score_ = score;
    scoreText_.setString("Score: " + std::to_string(score_));
}

void GameStats::SetLives(int lives)
{
    lives_ = lives;
    livesText_.setString("Lives: " + std::to_string(lives_));
}

int GameStats::GetScore() const
{
    return score_;
}

int GameStats::GetLives() const
{
    return lives_;
}
int GameStats::GetHighScore() const
{
    return highScore_;
}

void GameStats::SetHighScore(int highScore)
{
    highScore_ = highScore;
    highScoreText_.setString("High Score: " + std::to_string(highScore_));
}

void GameStats::Reset()
{

    if (score_ > highScore_)
    {

        if (std::ofstream file{"Highscores.txt"})
        {
            file << score_;
        }
        SetHighScore(score_);
    }

    SetScore(0);
    SetLives(gGameConfig.startingLives);
}
