#include "Board.hpp"

Board::Board(float posX, float posY)
{
    grid.setSmooth(true);
  	grid.loadFromFile("res/images/Grid.png");

    board.setScale(BSCALE,BSCALE);
  	board.setTexture(grid);
  	board.setPosition(sf::Vector2f(posX,posY));
}

void Board::draw(sf::RenderWindow &window)
{
    window.draw(board);
}

sf::Sprite Board::getBoard()
{
    return board;
}
