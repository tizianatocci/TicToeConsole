#include "Player.h"

bool Player::X_assigned = false;

Player::Player(std::string playername)
: name(playername)
{ 
    if (!X_assigned){
        symbol = " X ";
        X_assigned = true;
    } else {
        symbol = " O ";
    }
    std::cout << name << " has the symbol: " << symbol << std::endl;

} 

Player::~Player()
{
}



std::string Player::get_symbol() const{
    return symbol;
}

int Player::choose_move() const{
    std::cout << name << ", where do you want to put your symbol?\nChoose a position between 1 and 9: ";
    int position;
    std::cin >> position;
    std::cout << "Player " << name << " chose position " << position << std::endl;

    return position;
    }