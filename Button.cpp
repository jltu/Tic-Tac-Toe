#include "Button.hpp"

//creates a restart button at the given position
Button::Button(float posX, float posY)
{
    //load texture
    restart.setSmooth(true);
    restart.loadFromFile("res/images/Restart.png");

    //makes a button at given position
    button.setScale(RESTART_SCALE,RESTART_SCALE);
    button.setTexture(restart);
    button.setPosition(posX, posY);
}

//draw the button
void Button::draw(sf::RenderWindow &window)
{
    window.draw(button);
}

//return the button
sf::Sprite Button::getButton()
{
    return button;
}
