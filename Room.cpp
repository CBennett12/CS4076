#include "Room.h"

Room::Room()
{
    ;
}

Room::Room(int roomNumber)
{
    setExits(roomNumber);
}

void Room::setExits(int roomNumber)
{
    signed int tempRoom = roomNumber;
    signed int tempGlobal = global;
    int* exits = new int[4];
    if(tempRoom - tempGlobal < 0) // Can move north
        exits[0] = -1;
    else
        exits [0] = roomNumber - 10;
    if(tempRoom + tempGlobal > global * global) //Can move south
        exits[1] = -1;
    else
        exits[1] = roomNumber + 10;
    if(tempRoom % tempGlobal == 9) //Can move east
        exits[2] = -1;
    else
        exits[2] = roomNumber + 1;
    if(tempRoom % tempGlobal == 0) //Can move west
        exits[3] = -1;
    else
        exits[3] = roomNumber -1;
}

int Room::checkExit(int currentRoom, int nextRoom)
{
    return 4;
}

