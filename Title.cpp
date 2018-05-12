#include "Title.hpp"

Title::Title(float posX, float posY)
{
    //set background texture
    title.setSmooth(true);
    title.loadFromFile("res/images/Game Title.png");

    //set sprite texture
    sTitle.setScale(1,1);
    sTitle.setTexture(title);
    sTitle.setPosition(posX, posY);
}

void Title::draw(sf::RenderWindow &window)
{
    window.draw(sTitle);
}
