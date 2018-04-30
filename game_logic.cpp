#include "game_logic.hpp"
void update_ Board(int &board[27])
{
    this->gameBoard[] = board[];
}
int check_box(int map_index)
{
    return gameBoard[map_index];
}
int check_win()
{
    for(int i = 0; i < 49; i++) // check which player win
    {
        if((gameBoard[m_scoring[i][1]] == 1) && (gameBoard[m_scoring[i][2]] == 1)  && (gameBoard[m_scoring[i][1]] == 1))
        {
            return 1; //player 1 win
        }
        
        if((gameBoard[m_scoring[i][1]] == 2) && (gameBoard[m_scoring[i][2]] == 2)  && (gameBoard[m_scoring[i][1]] == 2))
        {
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
