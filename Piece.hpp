#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"

//Piece Class used by the Board Class

class Piece{
private:
    sf::Texture otexture;
    sf::Texture xtexture;
    sf::Sprite piece[3][3];
public:
    //given a board's coordinate constructs the array of pieces
    Piece(float posX, float posY);

    //makes the pieces invisible
    void reset();
    //makes the specified piece visible given the specified coordinate
    void setVisible(int x, int y);

    //changes the texture into O or X given the specified coordinate
    void setO(int x, int y);
    void setX(int x, int y);

    //draws all the pieces
    void draw(sf::RenderWindow &window);
};
