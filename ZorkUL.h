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
	void goRoom(Command command);
    void createItems();
    void displayItems();
    void dropItem(Command command);
    void scan(Command command);
    void useAttack(Command command);
public:
	ZorkUL();
	void play();
	string go(string direction);
    bool moveSet;
    bool scanSet;
    bool tacticalSet;
    Command* moveCommand;
    Command* scanCommand;
    Command* tacticalCommand;

};

#endif /*ZORKUL_H_*/
