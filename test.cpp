// TEST TEXTURE LOADING INTO SPRITE

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600


int main()
{
  // Create window // the style makes it so you can't resize the window
  sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TEST");

  ///// Texture
  sf::Texture t1;
  if (!t1.loadFromFile("res/images/Grid.png"))
  {
    cout << "ERROR LOADING FROM FILE Grid.png" << endl;
  }

  // // Top-Left Board
  sf::Sprite b1;                            // Declares Sprite
  //b1.setScale(BOARD_SCALE,BOARD_SCALE);			// Scales width and height
  b1.setTexture(t1);				              // Assigns texture to the sprite
  b1.setPosition(0,0);	            // Positions sprite


  //////////////////~~~~~~~~~ Game Loop  ~~~~~~~~~//////////////////
  while (window.isOpen())
  {
    // Event Loop    [Check each event with every iteration of loop]
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        // Window can be closed by pressing Esc key or EOF
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
            std::cout << "shoots, brah" << std::endl;
            window.close();
          }
          break;
      }
    }

    window.clear(sf::Color(187,225,254));

    // Draw the Grids
    window.draw(b1);



    window.display();

  }
}
