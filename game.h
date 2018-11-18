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

private:
    void spawnPlayer();
    void spawnEnemies(Enemy[]);
    void makeMap(Room[]);
    void gameLoop();

    Enemy tempEnemy;
    Room* map;
    Room temp;

};

#endif // GAME_H
