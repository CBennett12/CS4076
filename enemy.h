#ifndef ENEMY_H
#define ENEMY_H
#include <ship.h>


class Enemy : public Ship
{
public:
    Enemy();
    ~Enemy();

private:
    void moveToRoom(Room);
    void shoot();
    void toString();
};

#endif // ENEMY_H
