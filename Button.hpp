#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"

class Button
{
private:
    sf::Texture restart;
    sf::Sprite button;
public:
    //creates a restart button at the given position
    Button(float posX, float posY);

    //draw the button given a reference to a window
    void draw(sf::RenderWindow &window);

    //return the button
    sf::Sprite getButton();
};
