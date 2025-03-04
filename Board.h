#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
#include "Board_Utils.h"
#include <iostream>
#include <utility> 

using namespace std;

class Board
{
    friend std::ostream &operator<<(std::ostream &os, const Board &obj);
private:
    static constexpr int size_m=3;
    std::string table[size_m][size_m] ={};
    
public:
    Board();
    void print_board();
    std::pair<int,int> getdoubleindexes(int &position) const;
    //bool check_position_sanity(int &position) const;
    bool check_position_empty(int &position) const;
    bool check_move_sanity(int &position) const;
    bool insert_symbol(Player &player, int &position);
    bool check_horizontal(Player &player, int &row);
    bool check_vertical(Player &player, int &col);
    bool check_diagonal(Player player, int &row, int &col);
    bool check_anti_diagonal(Player player, int &row, int &col);
    bool check_if_tris(Player &player);
    bool check_if_full();
    ~Board();

};

#endif // BOARD_H
