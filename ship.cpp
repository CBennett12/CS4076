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
 ;
}

Ship::~Ship()
{

}

void Ship::shoot()
{
    torpedo--;
    //call constructor on torpedo using current heading of ship
}

void Ship::layMine()
{
    mine--;
    //call constructor on mine in current room
}
