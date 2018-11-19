#include "enemy.h"
#include "game.h"
#include "Room.h"
#include <cstdlib>

Enemy::Enemy()
{
    //currentRoom = assign to a random room on creation, should be the map made in the game class, but not sure how to access it
    torpedo = 1;
    health = 1;
    mines = 1;
}

void Enemy::moveToRoom(Room)
{
    ;//given a random room unless the player uses active scanning
    //Basically will be check to see if its > +10 or -10, and head north/south
    // if it's between +10 && -10, it moves left or right
}

void Enemy::shoot()
{
   //if enemy is ahead of the current head of the ship, shoot. if torpedo = 1; then reload or deploy a mine based
}
