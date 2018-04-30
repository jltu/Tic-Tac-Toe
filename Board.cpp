#include "Board.hpp"

Board::Board(float posX, float posY):
    piece(posX, posY)
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
    piece.draw(window);
}

void Board::clear()
{
    piece.reset();
}

void Board::X(int x, int y)
{
    piece.setX(x, y);
}

void Board::O(int x, int y)
{
    piece.setO(x, y);
}

void Board::visible(int x, int y)
{
    piece.setVisible(x, y);
}

sf::Sprite Board::getBoard()
{
    return board;
}
