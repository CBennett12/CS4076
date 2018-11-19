#ifndef SHIP_H
#define SHIP_H
#include "uno.h"

#include <string>
#include <QString>
#include <iostream>
#include "Room.h"

using std::string;

class Ship : public uno
{
public:
    Ship();
    ~Ship();

protected:
    int torpedo, mines, health;
    string heading;
    Room currentRoom;
    string setHeading(Room);
    void shoot();
    void layMine();
};

#endif // SHIP_H
