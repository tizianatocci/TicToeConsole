#include "Board.h"


// constructor
Board::Board()
{
    for(int i=0; i<size_m; i++)  
    {
        for(int j=0; j< size_m; j++)  
        {
            table[i][j] = " . ";  
        }
    }
}

// destructor
Board::~Board()
{
}

std::pair<int,int> Board::getdoubleindexes(int &position) const{
    // convert position to row and col
    int row = (position - 1) / size_m; 
    int col = (position - 1) % size_m;
    return std::make_pair(row, col);
}
    
/*
bool Board::check_position_sanity(int &position) const{
    if (position < 1 || position>9)
        {std::cout << "Your position is invalid. Insert a number between 1 and 9." << std::endl;
        return false;
        }
    else
        {return true;}
        
} */

bool Board::check_position_empty(int &position) const{
    // convert position to row and col
    std::pair<int, int> indices = Board::getdoubleindexes(position);
    int row=indices.first;
    int col=indices.second;
    if (table[row][col] != " . "){
        std::cout <<("The position is already full.");
        return false;}
    else{
        return true;
        }
}


bool Board::check_move_sanity(int &position) const{
    if (check_position_sanity(position) && Board::check_position_empty(position)){
        return true;}
    else{
        return false;
        }
    
    }

bool Board::insert_symbol(Player &player, int &position){
    if (Board::check_move_sanity(position)){
        std::pair<int, int> indices = Board::getdoubleindexes(position);
        int row=indices.first;
        int col=indices.second;
        table[row][col] = player.symbol;
        return true;}
    return false;
    };

bool Board::check_horizontal(Player &player, int &row){
    std::string current_symbol{player.symbol};
    for (int i_col{0}; i_col < size_m; i_col++){
        if (table[row][i_col] != current_symbol) {
            return false;
        }
    }
    return true;
}

bool Board::check_vertical(Player &player, int &col){
    std::string current_symbol{player.symbol};
    for (int i_row{0}; i_row < size_m; i_row++){
        if (table[i_row][col] != current_symbol) {
            return false;
        }
    }
    return true;
}

bool Board::check_diagonal(Player player, int &row, int &col){
    std::string current_symbol{player.symbol};
    for (int index{0}; index < size_m; index++){
        if (table[row+index][col+index] != current_symbol){
            return false;
        }
    
    }
    return true;
};


bool Board::check_anti_diagonal(Player player, int &row, int &col){
    std::string current_symbol{player.symbol};
    for (int index{0}; index < size_m; index++){
        if (table[row+index][col-index] != current_symbol){
            return false;
        }
    
    }
    return true;
};



bool Board::check_if_tris(Player &player){
    std::string current_symbol=player.symbol;
    for(int row=0;  row<size_m; row++)  
    {
        for(int col=0; col < size_m; col++)  
        {
            if(table[row][col] == current_symbol) {
                if (col==0 && Board::check_horizontal(player, row)){
                    return true;
                }
                if (row==0 && Board::check_vertical(player, col)){
                    return true;
                }
                if (row==0 && col==0 && Board::check_diagonal(player, row, col)){
                    return true;}
                if (row==0 && col==2 && Board::check_anti_diagonal(player, row, col)){
                    return true;}
            }
        }
    }
    return false;
}

bool Board::check_if_full(){
    for(int row=0;  row<size_m; row++)  
    {
        for(int col=0; col < size_m; col++)  
        {
            if(table[row][col] == " . ") {
                return false;
            }
        }
    }
    return true;
}

// << operator overloading
std::ostream &operator<<(std::ostream &os, const Board &obj){
    for(int i=0;  i<obj.size_m; i++)  
    {
        for(int j=0; j < obj.size_m; j++)  
        {
            std::cout<< obj.table[i][j];  
        }
    std::cout<<std::endl;  
    }
    return os;
}