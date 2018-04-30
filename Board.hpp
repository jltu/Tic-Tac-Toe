#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "Piece.hpp"

class Board{
private:
    sf::Texture grid;
    sf::Sprite board;
    Piece piece;
public:
    //creates a board at the given coordinates
    Board(float posX, float posY);

    //draws the board with pieces
    void draw(sf::RenderWindow &window);

    //resets pieces to 0% opacity
    void clear();

    //makes piece into 100% opacity
    void visible(int x, int y);

    void X(int x, int y);

    void O(int x, int y);

    //returns the board
    sf::Sprite getBoard();
};
