#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"


class Piece{
private:
    sf::Texture otexture;
    sf::Texture xtexture;
    sf::Sprite piece[3][3];
public:
    Piece(float posX, float posY);

    void reset();
    void setO(int x, int y);
    void setX(int x, int y);
    void setVisible(int x, int y);
    void draw(sf::RenderWindow &window);
};
