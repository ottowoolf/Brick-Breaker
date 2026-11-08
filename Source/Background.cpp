#include "Background.h "

Background::Background() : backgroundTexture_("Content/Images/SpaceBG_600x800.png"), backgroundSprite_(backgroundTexture_)
{
}

void Background::Draw(sf::RenderWindow &window) const
{
    window.draw(backgroundSprite_);
}