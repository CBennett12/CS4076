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
    ~Player();
    void operator+(Enemy *sT);
    Player& operator=(const Player& p);
    string toString();

private:
    int maxHealth, maxMines, maxTorpedos, enigmaCodes;
};

#endif // PLAYER_H
