#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Definitions.hpp"
#include "GameLogic.hpp"
#include "Board.hpp"
#include "Texts.hpp"
#include "Title.hpp"
#include "Button.hpp"

int main()
{
    // Create the window (the style makes it so you can't resize the window)
  	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
        " \"3D\" Tic-Tac-Toe",sf::Style::Close);

    ////////////////////////<<<<<< BACKGROUND MUSIC >>>>>>>/////////////////////

    sf::Music music;
    if(!music.openFromFile("res/sounds/Background_music.ogg"))
    {
      std::cout << "Sound ERROR" << std::endl;
    }

    music.play();

    ////////////////////////<<<<<< TURN TEXT >>>>>>>////////////////////////////

    Texts xtext("X Turn");
    Texts otext("O Turn");
    Texts xwin("X Wins!");
    Texts owin("O Wins!");

    ////////////////////////<<<<<< SOUND EFFECTS >>>>>>>////////////////////////

    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("res/sounds/Bloop.wav"))
    {
      std::cout << "Sound ERROR" << std::endl;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);

    ////////////////////////<<<<<< Home Screen Declaration >>>>>>>//////////////

    //title initiliaze
    Title title(SCREEN_WIDTH/2 - (410)/2, SCREEN_HEIGHT/2 - (300)/2);

    //determines if game will start
    bool gameStart = false;

    ////////////////////////<<<<<< Restart Button >>>>>>>///////////////////////

    Button resbut(SPACE/2, SCREEN_HEIGHT - RESTART_SIZE - SPACE/2);

    //////////////////<<<<<< Mouse Input & Board Declaration >>>>>>>////////////

    //variables for mouse input
    int col, row;
    int map_index = 0;

    //initiliaze boards

    // Top-Left Board
  	Board b1(SPACE, SPACE);
    // Centered Board
    Board b2(SCREEN_WIDTH/2 - (BSIZE)/2, SCREEN_HEIGHT/2 - (BSIZE)/2);
    // Bottom-Right Board
    Board b3(SCREEN_WIDTH - BSIZE - SPACE, SCREEN_HEIGHT - BSIZE - SPACE);


    ///////////////////////<<<<<< O PIECE [class] >>>>>>>///////////////////////

    //Initialize game logic
    GameLogic board;

    ////////////////////////~~~~~~~~~ Game Loop  ~~~~~~~~~//////////////////////
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
                        int map_index = 0;
                        sf::Vector2i mpos = sf::Mouse::getPosition(window);

                        // Debug statement
                        std::cout << "mpos:" << "(" << mpos.x << "," << mpos.y << std::endl;

////////////////////////<<<<<< LOADING SCREEN >>>>>>>//////////////////////////////
                        if(gameStart == false) //if clicked title page, load game
                        {
                            std::cout << "Set to TRUE" << std::endl;
                            gameStart = true;
                        }
////////////////////////<<<<<< Running Game  >>>>>>>//////////////////////////////
                        else if(gameStart)
                        {   //takes in resbut, window, mpos, gamelogic, board
                            if (resbut.getButton().getGlobalBounds().contains(window.mapPixelToCoords(mpos)))
                            //if (mpos.x > resbut.getPosition().x && mpos.x < resbut.getPosition().x +
                            // RESTART_SIZE && mpos.y > resbut.getPosition().y && mpos.y < resbut.getPosition().y + RESTART_SIZE)
                            {   //if restart button pressed, clear boards and reset board logic
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

//board 1                   // First board only
                            if (mpos.x > b1.getBoard().getPosition().x && mpos.x < b1.getBoard().getPosition().x +
                             BSIZE && mpos.y > b1.getBoard().getPosition().y && mpos.y < b1.getBoard().getPosition().y + BSIZE)
                            {
                                // Check which column
                                if (mpos.x < b1.getBoard().getPosition().x + BSIZE/3) // First Column
                                {
                                    col = 1;
                                    std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                                }
                                else if (mpos.x > b1.getBoard().getPosition().x + BSIZE/3 && mpos.x <
                                    b1.getBoard().getPosition().x + 2*BSIZE/3) // Second Column
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
                                else if (mpos.y > b1.getBoard().getPosition().y + BSIZE/3 && mpos.y <
                                    b1.getBoard().getPosition().y + 2*BSIZE/3) // Second row
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

                                //if no piece there
                                if(board.check_box(map_index) == 0)
                                {
                                    sound.play();
                                    std::cout << "SOUND PLAY" << std::endl;
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
                            }//end board 1

//board 2                   //game logic board 2
                            if (mpos.x > b2.getBoard().getPosition().x && mpos.x < b2.getBoard().getPosition().x +
                                BSIZE && mpos.y > b2.getBoard().getPosition().y && mpos.y < b2.getBoard().getPosition().y + BSIZE)
                            {
                                map_index += 3;
                                // Check which column
                                if (mpos.x < b2.getBoard().getPosition().x + BSIZE/3) // First Column
                                {
                                    col = 1;
                                    std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                                }
                                else if (mpos.x > b2.getBoard().getPosition().x + BSIZE/3 && mpos.x <
                                    b2.getBoard().getPosition().x + 2*BSIZE/3) // Second Column
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
                                else if (mpos.y > b2.getBoard().getPosition().y + BSIZE/3 && mpos.y <
                                    b2.getBoard().getPosition().y + 2*BSIZE/3) // Second row
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
                                {   sound.play();
                                    std::cout << "SOUND PLAY" << std::endl;
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

                            }//end board 2

//board 3                   //game logic board 3
                            if (mpos.x > b3.getBoard().getPosition().x && mpos.x < b3.getBoard().getPosition().x +
                                BSIZE && mpos.y > b3.getBoard().getPosition().y && mpos.y < b3.getBoard().getPosition().y + BSIZE)
                            {
                                map_index += 6;
                                // Check which column
                                if (mpos.x < b3.getBoard().getPosition().x + BSIZE/3) // First Column
                                {
                                    col = 1;
                                    std::cout << "col1:" << "(" << mpos.x << "," << mpos.y << std::endl;
                                }
                                else if (mpos.x > b3.getBoard().getPosition().x + BSIZE/3 && mpos.x <
                                    b3.getBoard().getPosition().x + 2*BSIZE/3) // Second Column
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

                                //if no piece there
                                if(board.check_box(map_index) == 0)
                                {
                                    sound.play();
                                    std::cout << "SOUND PLAY" << std::endl;
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
                            }//end board 3

                            //debug:
                            //print what box they clicked on
                            //check if they won
                            std::cout << map_index << std::endl;
                            std::cout << board.check_win() << std::endl;
                        }//end checking mouse events of tic tac toe
                    }//end if statement if left mouse button pressed
                    break;
                }//end switch case mouse button released
            }//end switch event
        }//end while poll event

        // Sleep to free up resources
        sf::sleep(sf::seconds(1.0f/FPS)); // optional

        // Clear window before drawing
        window.clear(sf::Color(187,225,254));		// redraws background


///////////////<<<<<<<<<<<<< Draw everything here >>>>>>>>>>>>>>>///////////////
        if(gameStart == false)
        {
            //std::cout << "Game Start = false" << std::endl;
            title.draw(window);
        }
        else    //update graphics
        {
          if(board.check_current_player() == 1)
          {
            //std::cout << "X Turn" << std::endl;
            xtext.draw(window);
            //window.draw(xtext);
          }
          if(board.check_current_player() == 2)
          {
            //std::cout << "O Turn" << std::endl;
            otext.draw(window);
            //window.draw(otext);
          }
          if(board.check_win() == 1)
          {
            window.clear(sf::Color(187,225,254));
            xwin.draw(window);
            //window.draw(xwin);
          }
          else if(board.check_win() == -1)
          {
            window.clear(sf::Color(187,225,254));
            owin.draw(window);
            //window.draw(owin);
          }
            // Draw the Restart Button
            resbut.draw(window);

            // Draw the Grids and pieces [function]
            b1.draw(window);
            b2.draw(window);
            b3.draw(window);
        }

        // Redraws the Display
        window.display();

    } //end game loop

}
