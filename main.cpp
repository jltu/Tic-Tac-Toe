#include <SFML/Graphics.hpp>
#include <iostream>
//using namespace std;
//using namespace sf;

#define FPS 60.0f

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

#define BOARD_WIDTH 467
#define BOARD_LENGTH 466


int main()
{
  	// Create window // the style makes it so you can't resize the window
  	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), " \"3D\" Tic-Tac-Toe",sf::Style::Close);

    sf::Texture grid;
  	if (!bTexture.loadFromFile("res/images/Grid.png"))
  		std::cout << "ERROR: Could not load Board" << std::endl;

  	sf::Sprite board;				// Declares board
  	board.setScale(1,1);			// Scales width and height
  	board.setTexture(grid);				// assigns texture to the sprite
  	board.setPosition(SCREEN_WIDTH/2 - BOARD_WIDTH/2, SCREEN_HEIGHT/2 - BOARD_LENGTH/2);	// centers sprite

    // Game Loop
    while (window.isOpen())
    {
      // Event Loop    [Check each event with every iteration of loop]
      sf::Event event;
      while (window.pollEvent(event))
      {
        switch (event.type)
        {
          // To close the window
          case sf::Event::Closed:
            window.close();
            break;
          // Shortcut to close window
          case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
              std::cout << "See you next time" << std::endl;
              window.close();
            }
            break;
        }
      }

      // Sleep to free up resources
      sf::sleep(sf::seconds(1.0f/FPS)); // optional

      // Clear window before drawing
      window.clear(sf::Color(187,225,254));		// redraws background

      // Draw everything here>>>
      window.draw(board);
      window.display();		// redraws the display



    }
}
