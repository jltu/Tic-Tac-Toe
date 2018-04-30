#include "Piece.hpp"

Piece::Piece(float posX, float posY){
    // O Texture
    otexture.setSmooth(true);
    otexture.loadFromFile("res/images/O.png");
    // X Texture
    xtexture.setSmooth(true);
    xtexture.loadFromFile("res/images/X.png");

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
  		{
            piece[x][y].setScale(BSCALE,BSCALE);
            piece[x][y].setTexture(otexture);

            // Change last value to 0 in order to make pieces invisible
            piece[x][y].setColor(sf::Color(255, 255, 255, 0));
            // the -2 is needed to center the Piece
            piece[x][y].setPosition(posX + (PSIZE * x) - 2, posY + (PSIZE * y) - 2);
        }
    }
}

void Piece::reset(){
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            piece[x][y].setColor(sf::Color(255, 255, 255, 0));
        }
    }
}

void Piece::setO(int x, int y){
    piece[x][y].setTexture(otexture);
}

void Piece::setX(int x, int y){
    piece[x][y].setTexture(xtexture);
}

void Piece::setVisible(int x, int y){
    piece[x][y].setColor(sf::Color(255, 255, 255, 255));
}


void Piece::draw(sf::RenderWindow &window)
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            window.draw(piece[x][y]);
        }
    }
}
