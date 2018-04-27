#include <SFML/Graphics.hpp>
#include <iostream>
//using namespace std;
//using namespace sf;

// Definitions can be moved to DEFINITIONS.hpp later on
#define FPS 60.0f

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

#define BSCALE .33

#define BSIZE 466*BSCALE
#define BSIZE 466*BSCALE

#define SPACE 60

#define PSIZE 160*BSCALE

int main()
{
  	// Create window // the style makes it so you can't resize the window
  	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), " \"3D\" Tic-Tac-Toe",sf::Style::Close);

////////////////////////<<<<<< PLAYER [class] >>>>>>>//////////////////////////////
int turncount(1);



////////////////////////<<<<<< GRID [class] >>>>>>>//////////////////////////////
    // variables for mouse input
    int col, row;

    // Grid Texture
    sf::Texture grid;
    grid.setSmooth(true);
  	grid.loadFromFile("res/images/Grid.png");

    // Top-Left Board
  	sf::Sprite b1;                            // Declares Sprite
  	b1.setScale(BSCALE,BSCALE);			// Scales width and height
  	b1.setTexture(grid);				              // Assigns texture to the sprite
  	b1.setPosition(SPACE, SPACE);	            // Positions sprite

    // Centered Board
    sf::Sprite b2;
  	b2.setScale(BSCALE,BSCALE);
  	b2.setTexture(grid);
  	b2.setPosition(SCREEN_WIDTH/2 - (BSIZE)/2, SCREEN_HEIGHT/2 - (BSIZE)/2);	// centers sprite

    // Bottom-Right Board
    sf::Sprite b3;
    b3.setScale(BSCALE,BSCALE);
    b3.setTexture(grid);
    b3.setPosition(SCREEN_WIDTH - BSIZE - SPACE, SCREEN_HEIGHT - BSIZE - SPACE);


////////////////////////<<<<<< O PIECE [class] >>>>>>>//////////////////////////////

    // O Texture
    sf::Texture otexture;
    otexture.setSmooth(true);
    otexture.loadFromFile("res/images/O.png");

    // X Texture
    sf::Texture xtexture;
    xtexture.setSmooth(true);
    xtexture.loadFromFile("res/images/X.png");

    // Initialize Sprites as Arrays
    sf::Sprite o1[3][3];
    sf::Sprite o2[3][3];
    sf::Sprite o3[3][3];

    // First Board (b1)
    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
  		{
        o1[x][y].setScale(BSCALE,BSCALE);
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
        o2[x][y].setScale(BSCALE,BSCALE);
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
        o3[x][y].setScale(BSCALE,BSCALE);
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
            default:
                break;
                
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
