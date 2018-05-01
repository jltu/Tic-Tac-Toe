#include "Texts.hpp"

Texts::Texts(std::string word)
{
  if (!font.loadFromFile("res/fonts/Marker Felt.ttf"))
  {
    std::cout << "FONT ERROR" << std::endl;
  }

  text.setFont(font);
  text.setString(word);
  text.setCharacterSize(50);
  text.setColor(sf::Color(54, 57, 67, 255));
  text.setPosition(430,15);
}

void Texts::draw(sf::RenderWindow &window)
{
  window.draw(text);
}
