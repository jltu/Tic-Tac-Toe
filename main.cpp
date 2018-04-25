#include <SFML/Graphics.hpp>
#include <iostream>
#include <DEFINITIONS.hpp>
//using namespace std;
//using namespace sf;

// Definitions can be moved to DEFINITIONS.hpp later on
#define FPS 60.0f

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

#define BOARD_SCALE .33

#define BOARD_WIDTH 467*BOARD_SCALE
#define BOARD_LENGTH 466*BOARD_SCALE

#define BOARD_SCALE .33

#define SPACE 60


int main()
{
  	// Create window // the style makes it so you can't resize the window
  	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), " \"3D\" Tic-Tac-Toe",sf::Style::Close);

    // Grid Texture
    sf::Texture grid;
  	if (!grid.loadFromFile("res/images/Grid.png"))
  		std::cout << "ERROR: Could not load Board" << std::endl;

    // Top-Left Board
  	sf::Sprite b1;                            // Declares Sprite
  	b1.setScale(BOARD_SCALE,BOARD_SCALE);			// Scales width and height
  	b1.setTexture(grid);				              // Assigns texture to the sprite
  	b1.setPosition(SPACE, SPACE);	            // Positions sprite

    // Centered Board
    sf::Sprite b2;
  	b2.setScale(BOARD_SCALE,BOARD_SCALE);
  	b2.setTexture(grid);
  	b2.setPosition(SCREEN_WIDTH/2 - (BOARD_WIDTH)/2, SCREEN_HEIGHT/2 - (BOARD_LENGTH)/2);	// centers sprite

    // Bottom-Right Board
    sf::Sprite b3;
    b3.setScale(BOARD_SCALE,BOARD_SCALE);
    b3.setTexture(grid);
    b3.setPosition(SCREEN_WIDTH - BOARD_WIDTH - SPACE, SCREEN_HEIGHT - BOARD_LENGTH - SPACE);


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


// <<<<<<<<<<<<< Draw everything here >>>>>>>>>>>>>>>
      // Draw the menu
      // window.draw(menu);

      // Draw the Grids
      window.draw(b1);
      window.draw(b2);
      window.draw(b3);

      // Draw the Pieces



      // Redraws the Display
      window.display();



    }
}
