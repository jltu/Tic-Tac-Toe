#pragma once

#include "game_logic.hpp"

GameLogic::GameLogic()
{
    //gameBoard[27] = {0};
    gameOver = 0;
    playerOneTurn = 1;
    playerTwoTurn = 1;
}

void GameLogic::update_Box(int map_index)
{
    if(playerOneTurn)
    {
        this->gameBoard[map_index] = 1;
    }
    else if(playerTwoTurn)
    {
        this->gameBoard[map_index] = 2;
    }
}

int GameLogic::check_box(int map_index)
{
    return gameBoard[map_index];
}

int GameLogic::check_win()
{
    for(int i = 0; i < 49; i++) // check which player win
    {
        if((gameBoard[m_scoring[i][0]] == 1) && (gameBoard[m_scoring[i][1]] == 1)  && (gameBoard[m_scoring[i][2]] == 1))
        {
            std::cout<< m_scoring[i][0] <<","<<m_scoring[i][1] << "," << m_scoring[i][2]<<std::endl;

            return 1; //player 1 win
        }

        if((gameBoard[m_scoring[i][0]] == 2) && (gameBoard[m_scoring[i][1]] == 2)  && (gameBoard[m_scoring[i][2]] == 2))
        {
            std::cout<< m_scoring[i][0] <<","<< m_scoring[i][1] << "," << m_scoring[i][2]<<std::endl;
            return -1;//player 2 win


        }
    }
    for(int i = 0; i < 27; i++)//check for empty boxes
    {
        if(gameBoard[i] == 0)
        {
            return 0;// continue game
        }
    }

    return 2; // game tied
}

void GameLogic::change_player_turn()
{
    if(playerOneTurn)
    {
        playerOneTurn = 0;
        playerTwoTurn = 1;
    }
    else
    {
        playerOneTurn = 1;
        playerTwoTurn = 0;
    }
}

int GameLogic::check_current_player()
{
    if(playerOneTurn)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
