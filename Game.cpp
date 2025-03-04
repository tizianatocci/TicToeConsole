#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

Board Game::create_board(){
    Board b;
    cout << "Welcome to Tic Toe!" << endl;
    cout << b;
    return b;
}

Player Game::create_player(){
    std::cout << "What is the name of the player?: ";
    std::string namePlayer;
    std::cin >> namePlayer;
    Player player{namePlayer};

    return player;
}

bool Game::play_turn(Player &player, Board &board){
    bool flag_symbol_inserted=false;
    while (!flag_symbol_inserted){
        int position = player.choose_move();
        flag_symbol_inserted = board.insert_symbol(player, position);}
    cout << board;
    
    bool flag_tris = board.check_if_tris(player);
    // std::cout << "Did " <<  player.name<< " win?: " << flag_tris << std::endl;
    if (flag_tris==1){
        return true;}
        
    return false;
}

void Game::compliment_winner(Player &player){
    std::cout << "Congratulations, " << player.name << " won!";
    }
    
void Game::declare_no_winner(){
    std::cout << "The game finished and no one won.";
}

void Game::play_game(Player &p1, Player &p2, Board &b){
    Player *current_player = &p1;
    Player *next_player = &p2;

    bool flag_win{false};
    bool flag_end{false};
    
    while (!flag_win && !flag_end){
        flag_win = play_turn(*current_player,b);
        if (flag_win){
            compliment_winner(*current_player);
            break;
        }
        flag_end = b.check_if_full();
        if (flag_end){
            declare_no_winner();
            break;}
        
        std::swap(current_player, next_player);
    }

}