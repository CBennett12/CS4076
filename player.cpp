#include "player.h"

Player::Player()
{

}

void Player::operator+(Enemy sT)
{
    health = maxHealth;
    torpedo = maxTorpedos;
    mine = maxMines;
    enigmaCodes++;
}
