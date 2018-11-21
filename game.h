#ifndef GAME_H
#define GAME_H
#include <Room.h>
#include <enemy.h>
#include <starter.h>
#define globalHalfed global/2
#define halfedGlobal 5

class Game
{
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

    bool moveSet;
    bool scanSet;
    bool tactSet;
    string commands[3];
    int playerHealth, playerTorpedos, playerMines, playerCodes, maxHealth, maxTorpedos, maxMines, piecesNeeded;
    const unsigned int halfGlobal;
    Enemy tempEnemy;
    //Room* map;
    //Enemy enemies[globalHalfed];
    Enemy enemies[halfedGlobal];
    Uno *map[100];


};

#endif // GAME_H
