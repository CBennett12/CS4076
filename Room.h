#ifndef ROOM_H
#define ROOM_H

#include <uno.h>
#include <starter.h>

class Room
{

public:
    Room();
    Room(int);
    int checkExit(int, int); //current room, heading, returns -1 if unable to move
    //uno isOccupied();
    int getIndex();


private:
    void setExits(int);
    signed int tempRoom, global;
    int* exits;
    //uno occupies;
    int index;
};

#endif // ROOM_H
