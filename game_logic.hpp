#include <iostream.h>
class GameLogic {
private:
    int gameBoard [3][3][3];
    bool gameOver = 0;
    

    
    
public:
    GameLogic();
    void check_win();
};
