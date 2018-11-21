#include "player.h"

Player::Player()
{
    this->type = UnoType::Player;
}

void Player::operator+(Enemy *sT)
{
    health = maxHealth;
    torpedo = maxTorpedos;
    mine = maxMines;
    enigmaCodes++;
    delete sT;
}

string Player::toString()
{
    return("player");
}


