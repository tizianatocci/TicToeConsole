#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"


class Game{
public:
    Game();
    ~Game();
    
    Board create_board();
    Player create_player();
    bool play_turn(Player &player, Board &board);
    void play_game(Player &p1, Player &p2, Board &b);
    void compliment_winner(Player &player);
    void declare_no_winner();
};

#endif // GAME_H
