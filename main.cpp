#include <SFML/Graphics.hpp>
#include <iostream>
//using namespace std;
//using namespace sf;

#define FPS 60.0f

int main()
{

  	// vectors to initialize dimensions
  	sf::Vector2i screenDimensions(640,480);

  	// Create window [object?]
  	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), " \"3D\" Tic-Tac-Toe",sf::Style::Close);

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
      window.display();		// redraws the display



    }
}
