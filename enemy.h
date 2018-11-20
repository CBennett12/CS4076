#ifndef ENEMY_H
#define ENEMY_H
#include <ship.h>


class Enemy : public Ship
{
public:
    Enemy();

private:
    void moveToRoom(Room);
    void shoot();
    string toString();
};

#endif // ENEMY_H
