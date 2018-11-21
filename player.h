#ifndef PLAYER_H
#define PLAYER_H
#include <enemy.h>
#include <ship.h>
#include <uno.h>
using namespace std;

class Player : public Ship
{
public:
    Player();
    void operator+(Enemy *sT);

private:
    int maxHealth, maxMines, maxTorpedos, enigmaCodes;
    string toString();
};

#endif // PLAYER_H
