#include "game.h"
#include "Room.h"
#include "player.h"
#include <string>
#include <iostream>
#include <QTextStream>
#include <qmessagebox.h>
#define globalSquared global*global




Game::Game() :halfGlobal(global/2) //tried using initializer
{
    srand(time(NULL)); //makes random numbers random
    //Uno* pMap [100];
    //makeMap(pMap);
    srand(time(NULL)); //makes random numbers random
    string commands[3];
    /*
     * commands[0] = moveCommand
     * commands[1] = scanCommand
     * commands[2] = tacticalComand
     **/
    moveSet = false;
    scanSet = false;
    tactSet = false;

    playerHealth = maxHealth = 5;
    playerTorpedos = maxTorpedos = 5;
    playerMines = maxMines = 5;
    piecesNeeded = global/2;
    playerCodes = 0;
    pPtr = new Player();
    for(int i = 0; i < halfGlobal; i++)
        enemies[i] = new Enemy();

    populatePlayer(map, pPtr);
    //populateMap(map, enemies);
}

void Game::spawnEnemies(Enemy arr [])
{
    for(int i = 0; i < static_cast<int>(global); i++)
    {
        Enemy *tempEnemy = new Enemy();
        arr[i] = *tempEnemy;
    }
}

void Game::spawnPlayer()
{

}

void Game::makeMap(Uno *map[])
{
    for(unsigned int i = 0; i < globalSquared; i++)
    {
        map[i] = nullptr;

    }
    /*
    map[14] = new Player();
    map[83] = new Enemy();*/
}

//the next 3 functions all set the command inputted to the array, and set their relevant booleans
void Game::setCommand(string command, int index)
{
    commands[index]=command;
    moveSet=true;
    switch (index) {
    case 0: moveSet=true;
    case 1: scanSet=true;
    case 2: tactSet=true;
    }
}

//Handler for the movement command
void Game::useMove()
{
    if (commands[0].compare("1")==0)
    {
        //Go Forward
    }
    else
        if (commands[0].compare("2")==0)
        {
            //Go Backwards
        }
        else
            if (commands[0].compare("3")==0)
            {
                //Turn Port
            }
            else
                if (commands[0].compare("4")==0)
                {
                    //Turn Starboard
                }
}

//handler for the scanning command
void Game::useScan()
{
    if (commands[1].compare("1")==0)
    {
        //Passive Scan
    }
    else
        if (commands[1].compare("2")==0)
        {
            //Active Scan
        }
}

//Handler for the tactical command
void Game::useAttack()
{
    if (commands[2].compare("1")==0)
    {
        //Lay Mine
        if (playerMines != 0)
        {
            //player.layMine();
            playerMines--;
        }
    }
    else
        if (commands[2].compare("2")==0)
        {
            //Fire Torpedo North
            if (playerTorpedos != 0)
            {
                //player.shoot();
                playerTorpedos--;
            }
        }
        else
            if (commands[2].compare("3")==0)
            {
                //Fire Torpedo South
                if (playerTorpedos != 0)
                {
                    //player.shoot();
                    playerTorpedos--;
                }
            }
            else if (commands[2].compare("4")==0)
            {
                //Fire Torpedo East
                if (playerTorpedos != 0)
                {
                    //player.shoot();
                    playerTorpedos--;
                }
            }
            else
                if (commands[2].compare("5")==0)
                {
                    //Fire Torpedo West
                    if (playerTorpedos != 0)
                    {
                        //player.shoot("West");
                        playerTorpedos--;
                    }
                }
                else
                    if (commands[2].compare("6")==0)
                    {
                        //Salvage Wreckage

                        //player+ship()

                        /*
                 * if (room has a destroyed ship)
                 * {
                 *  playership=playerShip+destroyedShip;
                 * }
                 */
                        playerCodes++;
                        playerTorpedos=maxTorpedos;
                        playerMines=maxMines;
                        playerHealth=maxHealth;
                    }
}

//A pretty Ronseal function, resets the commands array and booleans
void Game::resetCommands()
{
    for (int i=0; i<(3);i++)
    {
        commands[i]="";
    }
    moveSet=false;
    scanSet=false;
    tactSet=false;
}

int Game :: getPH() const
{
    return playerHealth;
}

int Game :: getTorps() const
{
    return playerTorpedos;
}

int Game :: getMines() const
{
    return playerMines;
}

int Game :: getPN() const
{
    return (piecesNeeded-playerCodes);
}

bool Game :: getMove() const
{
    return moveSet;
}

bool Game :: getScan() const
{
    return scanSet;
}

bool Game :: getTact() const
{
    return tactSet;
}

Uno** Game::getMap()
{
    return map;
}

void Game::populateMap(Uno** map, Enemy** enemies)
{
    int num = rand()%100;
    for (int i = 0; i < global/2; i++)
    {

            num = rand()%100;
            if(map[num] == nullptr)
            {
                populatedRooms.push_back(num);
                map[num] = enemies[i];
            }
    }
}

void Game::populatePlayer(Uno** map, Player* ptr)
{
    int num = rand()%100;
    populatedRooms.push_back(num);
    map[num] = pPtr;
}
