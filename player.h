#ifndef PLAYER_H
#define PLAYER_H
#include <enemy.h>
#include <ship.h>

class Player : public Ship
{
public:
    Player();

    void operator+(Enemy sT);

private:
    int maxHealth, maxMines, maxTorpedos, enigmaCodes;
};

#endif // PLAYER_H