#include <iostream>
#include <SFML/Graphics>

class Board
{
protected:

public:

};

class Player
{
protected:
    std::string name;   //player name
    int score;  //number of wins

public:
    //Getters
    std::string getname();
    int getscore();

    //Setters
    void setname(std::string n);
    void setscore(int s);
};
