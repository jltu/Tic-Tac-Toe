#include <iostream>

class GameLogic
{
private:
    int gameBoard[27] = {};
    bool gameOver;
    bool playerOneTurn;
    bool playerTwoTurn;
    /* board representation
     (bottom)    (mid)        (top)
     level 1        level 2        level 3
     0   9  18    3  12  21    6  15  24
     1  10  19    4  13  22    7  16  25
     2  11  20    5  14  23    8  17  26
     Below is a list of winning squares; there are 49 possible wins.
     */

    const int m_scoring[49][3] = {
        // row & col
        {0, 1, 2},     {3, 4, 5},     {6, 7, 8},
        {9, 10, 11},     {12, 13, 14},     {15, 16, 17},
        {18, 19, 20},     {21, 22, 23},     {24, 25, 26},

        {0, 9, 18},    {1, 10, 19},    {2, 11, 20},
        {3, 12, 21},    {4, 13, 22},    {5, 14, 23},
        {6, 15, 24},    {7, 16, 25},    {8, 17, 26},

        {0, 3, 6},    {1, 4, 7},    {2, 5, 8},
        {9, 12, 15},    {10, 13, 16},    {11, 14, 17},
        {18, 21, 24},    {19, 22, 25},    {20, 23, 26},

        // diag
        {0, 10, 20},     {18, 10, 2},    {3, 13, 23},
        {21, 13, 5},     {6, 16, 26},    {24, 16, 8},

        {0, 12, 24},    {6, 12, 18},    {6, 4, 2},    {0, 4, 8},
        {2, 14, 26},    {8, 14, 20},    {20, 22, 24},    {18, 22, 26},
        {7, 13, 19},    {1, 13, 25},    {9, 13, 17},    {11, 13, 15},

        {0, 13, 26},    {6, 13, 20},    {2, 13, 24},    {8, 13, 18}
    };
public:
    GameLogic();
    void update_Box(int map_index);
    int check_box(int map_index);
    int check_win();
    void change_player_turn();
    int check_current_player();
};
