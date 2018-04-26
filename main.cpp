#include <SFML/Graphics.hpp>
#include <iostream>
//using namespace std;
//using namespace sf;

// Definitions can be moved to DEFINITIONS.hpp later on
#define FPS 60.0f

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

#define BOARD_SCALE .33

#define BOARD_WIDTH 466*BOARD_SCALE
#define BOARD_LENGTH 466*BOARD_SCALE

#define SPACE 60

#define PSIZE 160*BOARD_SCALE

int main()
{
  	// Create window // the style makes it so you can't resize the window
  	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), " \"3D\" Tic-Tac-Toe",sf::Style::Close);

////////////////////////<<<<<< GRID [class] >>>>>>>//////////////////////////////
    // variables for mouse input
    int col, row;

    // Grid Texture
    sf::Texture grid;
    grid.setSmooth(true);
  	grid.loadFromFile("res/images/Grid.png");

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


////////////////////////<<<<<< O PIECE [class] >>>>>>>//////////////////////////////

    // O Texture
    sf::Texture otexture;
    otexture.setSmooth(true);
    otexture.loadFromFile("res/images/O.png");

    // Initialize Sprites as Arrays
    sf::Sprite o1[3][3];
    sf::Sprite o2[3][3];
    sf::Sprite o3[3][3];

    // First Board (b1)
    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
  		{
        o1[x][y].setScale(BOARD_SCALE,BOARD_SCALE);
        o1[x][y].setTexture(otexture);
        o1[x][y].setColor(sf::Color(255, 255, 255, 0)); // Change last value to 0 in order to make pieces invisible
        o1[x][y].setPosition(b1.getPosition().x + (PSIZE * x) - 2, b1.getPosition().y + (PSIZE * y) - 2);     // the -2 is needed to center the Piece
      }
    }

    // Middle Board (b2)
    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        o2[x][y].setScale(BOARD_SCALE,BOARD_SCALE);
        o2[x][y].setTexture(otexture);
        o2[x][y].setColor(sf::Color(255, 255, 255, 255));
        o2[x][y].setPosition(b2.getPosition().x + (PSIZE * x) - 2, b2.getPosition().y + (PSIZE * y) - 2);
      }
    }

    // Bottom Board (b3)
    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        o3[x][y].setScale(BOARD_SCALE,BOARD_SCALE);
        o3[x][y].setTexture(otexture);
        o3[x][y].setColor(sf::Color(255, 255, 255, 255));
        o3[x][y].setPosition(b3.getPosition().x + (PSIZE * x) - 2, b3.getPosition().y + (PSIZE * y) - 2);
      }
    }



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
////////////////////////<<<<<< Mouse Input [class and functions] >>>>>>>//////////////////////////////
          case sf::Event::MouseButtonReleased:
          {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
              sf::Vector2i mpos = sf::Mouse::getPosition(window);

              // Debug statement
              std::cout << "mpos:" << "(" << mpos.x << "," << mpos.y << std::endl;


            // First board only [i guess an inheritance thing will be going on for each board]

              // Check which column
              if (mpos.x > b1.getPosition().x && mpos.x < b1.getPosition().x + BOARD_WIDTH/3) // First Column
              {
                col = 1;
                std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
              }
              else if (mpos.x > b1.getPosition().x + BOARD_WIDTH/3 && mpos.x < b1.getPosition().x + 2*BOARD_WIDTH/3) // Second Column
              {
                col = 2;
                std::cout << "col2:" << "(" << mpos.x << "," << mpos.y << std::endl;
              }
              else if (mpos.x > b1.getPosition().x + 2*BOARD_WIDTH/3 && mpos.x < b1.getPosition().x + BOARD_WIDTH) // Third Column
              {
                col = 3;
                std::cout << "col3:" << "(" << mpos.x << "," << mpos.y << std::endl;
              }

              // Check which row
              if (mpos.y > b1.getPosition().y && mpos.y < b1.getPosition().y + BOARD_LENGTH/3) // First row
              {
                row = 1;
                std::cout << "row1:" << "(" << mpos.x << "," << mpos.y << std::endl;
              }
              else if (mpos.y > b1.getPosition().y + BOARD_LENGTH/3 && mpos.y < b1.getPosition().y + 2*BOARD_LENGTH/3) // Second row
              {
                row = 2;
                std::cout << "row2:" << "(" << mpos.x << "," << mpos.y << std::endl;
              }
              else if (mpos.y > b1.getPosition().y + 2*BOARD_LENGTH/3 && mpos.y < b1.getPosition().y + BOARD_LENGTH) // Third row
              {
                row = 3;
                std::cout << "row3:" << "(" << mpos.x << "," << mpos.y << std::endl;
              }


              std::cout << "(" << col << "," << row << ")" << std::endl;
              o1[col-1][row-1].setColor(sf::Color(255, 255, 255, 255));

            }
            break;
          }
        }
      }

      // Sleep to free up resources
      sf::sleep(sf::seconds(1.0f/FPS)); // optional

      // Clear window before drawing
      window.clear(sf::Color(187,225,254));		// redraws background


// <<<<<<<<<<<<< Draw everything here >>>>>>>>>>>>>>>
      // Draw the menu [function] [work in progress]
      // window.draw(menu);

  /// Draw the Grids [function]
      window.draw(b1);
      window.draw(b2);
      window.draw(b3);

  /// Initialize the Pieces [function]
      // Top Board (b1)
      for (int x = 0; x < 3; x++)
  		{
  			for (int y = 0; y < 3; y++)
  			{
            window.draw(o1[x][y]);
  			}
  		}
      // Middle Board (b2)
      for (int x = 0; x < 3; x++)
      {
        for (int y = 0; y < 3; y++)
        {
            window.draw(o2[x][y]);
        }
      }
      // Bottom Board (b3)
      for (int x = 0; x < 3; x++)
      {
        for (int y = 0; y < 3; y++)
        {
            window.draw(o3[x][y]);
        }
      }






      // Redraws the Display
      window.display();
    }
}
