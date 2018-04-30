#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"

class Board{
private:
    sf::Texture grid;
    sf::Sprite board;
public:
    Board(float posX, float posY);
    void draw(sf::RenderWindow &window);
    sf::Sprite getBoard();
};
