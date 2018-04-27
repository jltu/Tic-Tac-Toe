// Trash code for possible implementations


for (int x = 0; x < 3; x++)
{
  for (int y = 0; y < 3; y++)
  {
    for (int z = 0; z < 3; z++)
    {
      opieces[x][y][z].setScale(BOARD_SCALE,BOARD_SCALE);
      opieces[x][y][z].setTexture(otexture);
      opieces[x][y][z].setColor(sf::Color(255, 255, 255, 0));
      switch (x)
      {
        case 0:
          opieces[x][y][z].setPosition(b1.getPosition().x + (O_WIDTH * x) - 2, b1.getPosition().y + (O_WIDTH * y) - 2);
          break;
        case 1:
          opieces[x][y][z].setPosition(b2.getPosition().x + (O_WIDTH * x) - 2, b2.getPosition().y + (O_WIDTH * y) - 2);
          break;
        case 2:
          opieces[x][y][z].setPosition(b3.getPosition().x + (O_WIDTH * x) - 2, b3.getPosition().y + (O_WIDTH * y) - 2);
          break;
      }
    }
  }
}





for (int x = 0; x < 3; x++)
{
  for (int y = 0; y < 3; y++)
  {
    for (int z = 0; z < 3; z++)
    {
      window.draw(opieces[x][y][z]);
    }
  }
}




// Click Sprites on first board (b1)
// First Column
std::cout << "xcheck:" << mpos.x << ">" << b1.getPosition().x + BOARD_WIDTH/3 << "?" << std::endl;
std::cout << "ycheck:" << mpos.y << "<" << b1.getPosition().y + BOARD_LENGTH << "?" << std::endl;

if (mpos.x > b1.getPosition().x && mpos.x < b1.getPosition().x + BOARD_WIDTH/3)
{
  std::cout << "COLUMN" << std::endl;

  // First Row
  if (mpos.y > b1.getPosition().y && mpos.y < b1.getPosition().y + BOARD_LENGTH/3)
  {
    std::cout << "CLICKED" << std::endl;
  }
}
