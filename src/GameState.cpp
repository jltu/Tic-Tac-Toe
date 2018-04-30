#include <GameState.hpp>


//Player Class
//Getters
std::string Player::getname(){
    return name;
}
int Player::getscore(){
    return score;
}
//Setters
void Player::setname(std::string n){
    name = n;
}
void Player::setscore(int score){
    score = s;
}
