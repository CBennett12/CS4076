#ifndef GAME_H
#define GAME_H
#include <Room.h>
#include <enemy.h>

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

private:
    void spawnPlayer();
    //void spawnEnemies(Enemy[]);
    void makeMap(Room[]);
    bool moveSet;
    bool scanSet;
    bool tactSet;
    string commands[3];
    int playerHealth, playerTorpedos, playerMines, playerCodes, maxHealth, maxTorpedos, maxMines, piecesNeeded;

    //Enemy tempEnemy;
    Room* map;
    Room temp;



};

#endif // GAME_H
