//Template for anything that will move. Ships, Torpedos specifically

#ifndef MOVEABLE_H
#define MOVEABLE_H
#include <Room.h>

template<class T>
class Moveable
{
public:
    Moveable();
    void moveRoom(Room);
};

#endif // MOVEABLE_H
