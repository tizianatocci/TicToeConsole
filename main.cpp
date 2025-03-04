#include "Board.h"
#include "Player.h"
#include "Game.h"

using namespace std;

int main(){
    //Player p1{"Tiziana"};
    //Player p2{"Andrea"};
    
    Game g;
    Board b;
    b=g.create_board();
    Player p1=g.create_player();
    Player p2=g.create_player();
    g.play_game(p1, p2, b);
}
