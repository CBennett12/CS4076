#ifndef SHIP_H
#define SHIP_H
#include <uno.h>


class Ship : public Uno
{
public:
    virtual Ship();
    virtual ~Ship();

protected:
    int torpedo, mine, health;
    string heading;
    Room currentRoom;
    string setHeading(Room);
    void shoot();
    void layMine();
};

#endif // SHIP_H
