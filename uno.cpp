#include "uno.h"


Uno::~Uno()
{
    ;
}

string Uno::toString()
{
    return("uno");
}

//template<typename t>
bool Uno::checkMove(int moveIndex) //NSEW
{
    bool valid = false;
    if(moveIndex > 10 && moveIndex < 90)
        valid = true;
    else if(!(moveIndex % 10 == 9))
        valid = true;
    else if(!(moveIndex % 10 == 0))
        valid = true;
    else if(moveIndex < 90)
        valid = true;
    return valid;
}
