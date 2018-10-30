#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
    void goRoom(string command);
    void createItems();
    void displayItems();
    void dropItem(Command command);
    void scan(string command);
    void useAttack(string command);
public:
	ZorkUL();
	void play();
    string go(string direction);
    bool moveSet;
    bool scanSet;
    bool tacticalSet;
    string commands[3];
    bool isMoveSet();
    bool isScanSet();
    bool isTactSet();
    void setMove(string command);
    void setScan(string command);
    void setTact(string command);
    void resetCommands();

};

#endif /*ZORKUL_H_*/
