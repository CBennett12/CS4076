#include "ship.h"
#include "Room.h"

inline Room heading(Room r)
{
    int x, y;
    //int currentRoom = r.getNum();
    //needs to be worked on
    return r.checkExit(x,y);
}

Ship::Ship()
{

}
