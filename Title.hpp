#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.hpp"

class Title
{
private:
    sf::Texture title;
    sf::Sprite sTitle;
public:
    //given posX, posY, constructs title screen
    Title(float posX, float posY);

    //draws the title screen
    void draw(sf::RenderWindow &window);
};
