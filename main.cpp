#include <iostream>

#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "game_logic.hpp"
#include "Board.hpp"
#include "Piece.hpp"


int main()
{
    // Create window // the style makes it so you can't resize the window
  	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), " \"3D\" Tic-Tac-Toe",sf::Style::Close);

////////////////////////<<<<<< PLAYER [class] >>>>>>>//////////////////////////////
//int turncount(1)

////////////////////////<<<<<< Home Screen Declaration] >>>>>>>//////////////////////////////
    sf::Texture title, background;
    title.setSmooth(true);
    title.loadFromFile("res/images/Game Title.png");

    background.loadFromFile("res/images/Background.png");

    sf::Sprite sTitle;
    sTitle.setScale(1,1);
    sTitle.setTexture(title);
    sTitle.setPosition(SCREEN_WIDTH/2 - (410)/2, SCREEN_HEIGHT/2 - (300)/2);

    bool gameStart = false;


////////////////////////<<<<<< Restart Button >>>>>>>//////////////////////////////

    // Restart Button texture
    sf::Texture restart;
    restart.setSmooth(true);
    restart.loadFromFile("res/images/Restart.png");

    // Initialize Button
    sf::Sprite resbut;
    resbut.setScale(RESTART_SCALE,RESTART_SCALE);
    resbut.setTexture(restart);
    resbut.setPosition(SPACE/2, SCREEN_HEIGHT - RESTART_SIZE - SPACE/2);



////////////////////////<<<<<< GRID [class] >>>>>>>//////////////////////////////
    // variables for mouse input
    int col, row;
    int map_index = 0;

    // Top-Left Board
  	Board b1(SPACE, SPACE);

    // Centered Board
    Board b2(SCREEN_WIDTH/2 - (BSIZE)/2, SCREEN_HEIGHT/2 - (BSIZE)/2);

    // Bottom-Right Board
    Board b3(SCREEN_WIDTH - BSIZE - SPACE, SCREEN_HEIGHT - BSIZE - SPACE);


////////////////////////<<<<<< O PIECE [class] >>>>>>>//////////////////////////////

    //Initialize game logic
    GameLogic board;

//////////////////~~~~~~~~~ Game Loop  ~~~~~~~~~//////////////////
    while (window.isOpen()) //game class
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
                int map_index = 0;
                sf::Vector2i mpos = sf::Mouse::getPosition(window);

                // Debug statement
                std::cout << "mpos:" << "(" << mpos.x << "," << mpos.y << std::endl;
////////////////////////<<<<<< LOADING SCREEN >>>>>>>//////////////////////////////
                if(gameStart == false)
                {
                    std::cout << "Set to TRUE" << std::endl;
                    gameStart = true;
                }
////////////////////////<<<<<< RESET button  >>>>>>>//////////////////////////////
                else if(gameStart) //if reset button pressed
                {
                    if (mpos.x > resbut.getPosition().x && mpos.x < resbut.getPosition().x + RESTART_SIZE && mpos.y > resbut.getPosition().y && mpos.y < resbut.getPosition().y + RESTART_SIZE)
                    {
                        board.reset_game();
                        std::cout << "restart clicked" << std::endl;

                        //Clear boards
                        b1.clear();
                        std::cout << "b1 reset" << std::endl;

                        // Middle Board (b2)
                        b2.clear();
                        std::cout << "b2 reset" << std::endl;

                        // Bottom Board (b3)
                        b3.clear();
                        std::cout << "b3 reset" << std::endl;
                    }

                  // First board only [i guess an inheritance thing will be going on for each board]
                  if (mpos.x > b1.getBoard().getPosition().x && mpos.x < b1.getBoard().getPosition().x + BSIZE && mpos.y > b1.getBoard().getPosition().y && mpos.y < b1.getBoard().getPosition().y + BSIZE)
                  {

                    // Check which column
                    if (mpos.x < b1.getBoard().getPosition().x + BSIZE/3) // First Column
                    {
                      col = 1;
                      std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.x > b1.getBoard().getPosition().x + BSIZE/3 && mpos.x < b1.getBoard().getPosition().x + 2*BSIZE/3) // Second Column
                    {
                      col = 2;
                        map_index += 9;
                      std::cout << "col2:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.x > b1.getBoard().getPosition().x + 2*BSIZE/3) // Third Column
                    {
                      col = 3;
                        map_index += 18;
                      std::cout << "col3:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }

                    // Check which row
                    if (mpos.y < b1.getBoard().getPosition().y + BSIZE/3) // First row
                    {
                      row = 1;
                      std::cout << "row1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.y > b1.getBoard().getPosition().y + BSIZE/3 && mpos.y < b1.getBoard().getPosition().y + 2*BSIZE/3) // Second row
                    {
                      row = 2;
                        map_index += 1;
                      std::cout << "row2:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.y > b1.getBoard().getPosition().y + 2*BSIZE/3) // Third row
                    {
                      row = 3;
                        map_index += 2;
                      std::cout << "row3:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }



                      if(board.check_box(map_index) == 0)
                      {
                          // Change Pieces Based on Turncount
                          std::cout << "(" << col << "," << row << ")" << std::endl;
                          b1.visible(col-1,row-1);
                          if (board.check_current_player() == 1)
                        {
                          b1.X(col-1,row-1);    // If player1
                        }
                        else if (board.check_current_player() == 2)
                        {
                          b1.O(col-1,row-1);    // If player2
                        }
                          board.update_Box(map_index);
                          board.change_player_turn();
                      }
                  }



                ////////////////////////////////////////////////////////////////
                  if (mpos.x > b2.getBoard().getPosition().x && mpos.x < b2.getBoard().getPosition().x + BSIZE && mpos.y > b2.getBoard().getPosition().y && mpos.y < b2.getBoard().getPosition().y + BSIZE)
                  {
                      map_index += 3;
                    // Check which column
                    if (mpos.x < b2.getBoard().getPosition().x + BSIZE/3) // First Column
                    {
                      col = 1;
                      std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.x > b2.getBoard().getPosition().x + BSIZE/3 && mpos.x < b2.getBoard().getPosition().x + 2*BSIZE/3) // Second Column
                    {
                      col = 2;
                        map_index += 9;
                      std::cout << "col2:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.x > b2.getBoard().getPosition().x + 2*BSIZE/3) // Third Column
                    {
                      col = 3;
                        map_index += 18;
                      std::cout << "col3:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }

                    // Check which row
                    if (mpos.y < b2.getBoard().getPosition().y + BSIZE/3) // First row
                    {
                      row = 1;
                      std::cout << "row1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.y > b2.getBoard().getPosition().y + BSIZE/3 && mpos.y < b2.getBoard().getPosition().y + 2*BSIZE/3) // Second row
                    {
                      row = 2;
                        map_index += 1;
                      std::cout << "row2:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.y > b2.getBoard().getPosition().y + 2*BSIZE/3) // Third row
                    {
                      row = 3;
                        map_index += 2;
                      std::cout << "row3:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }

                        //if no piece there
                      if(board.check_box(map_index) == 0)
                      {

                        // Change Pieces Based on Turncount
                        std::cout << "(" << col << "," << row << ")" << std::endl;
                        b2.visible(col-1,row-1);
                        if (board.check_current_player() == 1)
                        {
                          b2.X(col-1,row-1);    // If player1
                        }
                        else if (board.check_current_player() == 2)
                        {
                          b2.O(col-1,row-1);    // If player2
                        }
                          board.update_Box(map_index);
                          board.change_player_turn();
                      }

                  }

                  /////////////////////////////////////////////////////////////////
                  if (mpos.x > b3.getBoard().getPosition().x && mpos.x < b3.getBoard().getPosition().x + BSIZE && mpos.y > b3.getBoard().getPosition().y && mpos.y < b3.getBoard().getPosition().y + BSIZE)
                  {
                      map_index += 6;
                    // Check which column
                    if (mpos.x < b3.getBoard().getPosition().x + BSIZE/3) // First Column
                    {
                      col = 1;
                      std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.x > b3.getBoard().getPosition().x + BSIZE/3 && mpos.x < b3.getBoard().getPosition().x + 2*BSIZE/3) // Second Column
                    {
                      col = 2;
                        map_index += 9;
                      std::cout << "col2:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.x > b3.getBoard().getPosition().x + 2*BSIZE/3) // Third Column
                    {
                      col = 3;
                        map_index += 18;
                      std::cout << "col3:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }

                    // Check which row
                    if (mpos.y < b3.getBoard().getPosition().y + BSIZE/3) // First row
                    {
                      row = 1;
                      std::cout << "row1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.y > b3.getBoard().getPosition().y + BSIZE/3 && mpos.y < b3.getBoard().getPosition().y + 2*BSIZE/3) // Second row
                    {
                      row = 2;
                        map_index += 1;
                      std::cout << "row2:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }
                    else if (mpos.y > b3.getBoard().getPosition().y + 2*BSIZE/3) // Third row
                    {
                      row = 3;
                        map_index += 2;
                      std::cout << "row3:" << "(" << mpos.x << "," << mpos.y << std::endl;
                    }

                      if(board.check_box(map_index) == 0)
                      {
                        // Change Pieces Based on Turncount
                        std::cout << "(" << col << "," << row << ")" << std::endl;
                        b3.visible(col-1,row-1);
                        if (board.check_current_player() == 1)
                        {
                          b3.X(col-1,row-1);    // If player1

                        }
                        else if (board.check_current_player() == 2)
                        {
                          b3.O(col-1,row-1);   // If player2

                        }
                          board.update_Box(map_index);
                          board.change_player_turn();
                      }
                  }
                    std::cout<<map_index<<std::endl;

                    std::cout<<board.check_win()<<std::endl;
                }


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
            if(gameStart == false){
                   std::cout << "Game Start = false" << std::endl;
                   window.draw(sTitle);
            }

            else
            {
                  // Draw the Restart Button
                  window.draw(resbut);

                  // Draw the Grids and pieces [function]
                  b1.draw(window);
                  b2.draw(window);
                  b3.draw(window);
            }

            // Redraws the Display
            window.display();
          }
}
