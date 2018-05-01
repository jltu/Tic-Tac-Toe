#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include <iostream>

class Texts{
private:
  sf::Font font;
  sf::Text text;

public:
  Texts(std::string word);

  //void change_corner_text(std::string);
  void draw(sf::RenderWindow &window);
};
