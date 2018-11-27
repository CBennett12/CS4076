#include "player.h"

Player::Player()
{
    this->type = UnoType::Player;
}

Player::~Player()
{

}

void Player::operator+(Enemy *sT)
{
    health = maxHealth;
    torpedo = maxTorpedos;
    mine = maxMines;
    enigmaCodes++;
    delete sT;
}

Player& Player::operator=(const Player& p)
{
    //copy constructor
    Player tmp(p);
    this->health = p.health;
    this->torpedo = p.torpedo;
    this->mine = p.mine;
    this->enigmaCodes = p.enigmaCodes;
    return *this;
}

string Player::toString()
{
    return("player");
}


