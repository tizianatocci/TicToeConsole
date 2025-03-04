#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player
{
    friend class Board;
    friend class Game;
private:
    std::string name;
    std::string symbol;
    static bool X_assigned;
public:
    Player(std::string playername);
    ~Player();
    
    std::string get_symbol() const;
    int choose_move() const;
    
};

#endif // PLAYER_H
