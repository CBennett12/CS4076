#include "game.h"
#include "Room.h"
#define globalSquared global*global

Game::Game()
{
    Room* pMap = new Room[globalSquared];
    makeMap(pMap);

}

void Game::spawnEnemies(Enemy[] arr)
{
    for(int i = 0; i < global; i++)
    {
        Enemy tempEnemy = new Enemy();
        arr[i] = tempEnemy;
    }
}

void Game::spawnPlayer()
{

}

void Game::makeMap(Room* pMap)
{
    for(unsigned int i = 0; i < globalSquared; i++)
        pMap[i] = new Room(i);
}

void Game::gameLoop()
{


}
