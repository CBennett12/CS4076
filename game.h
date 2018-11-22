#ifndef GAME_H
#define GAME_H
#include <Room.h>
#include <enemy.h>
#include <starter.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <player.h>
#include <uno.h>
#define globalHalfed global/2
#define halfedGlobal 5

using namespace std;

class Game
{
friend class PlayerInput;
public:
    Game();
    ~Game();
    void turnUpdate();
    int getPH() const;
    int getTorps() const;
    int getPN() const;
    int getMines() const;
    bool getMove() const;
    bool getScan() const;
    bool getTact() const;
    void useScan();
    void useAttack();
    void useMove();
    void setCommand(string command, int index);
    void resetCommands();
    Uno** getMap();

private:
    void spawnPlayer();
    void spawnEnemies(Enemy[]);
    void makeMap(Uno* []);
    void populateMap(Uno**, Enemy*[]);
    void populatePlayer(Uno**, Player*);

    bool moveSet;
    bool scanSet;
    bool tactSet;
    string commands[3];
    int playerHealth, playerTorpedos, playerMines, playerCodes, maxHealth, maxTorpedos, maxMines, piecesNeeded;
    const unsigned int halfGlobal;
    Enemy tempEnemy;
    Player *pPtr;
    //Player *tPtr;
    //Room* map;
    //Enemy enemies[globalHalfed];
    Enemy *enemies[halfedGlobal];
    Uno *map[100];
    vector<int> populatedRooms;
    int playerRoom;
    int tempRoom;
};

#endif // GAME_H
