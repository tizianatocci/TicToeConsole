#include "Board_Utils.h"

bool check_position_sanity(int &position) {
    if (position < 1 || position>9)
        {std::cout << "Your position is invalid. Insert a number between 1 and 9." << std::endl;
        return false;
        }
    else
        {return true;}
        
}

