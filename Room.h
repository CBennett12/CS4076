#ifndef ROOM_H
#define ROOM_H

#include "uno.h"
#include "starter.h"

class Room
{

public:
    Room(int);
    int checkExit(int, int); //current room, heading, returns -1 if unable to move


private:
    void setExits(int);
    signed int tempRoom, global;
    int* exits;
};

#endif // ROOM_H
