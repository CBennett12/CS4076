#include <iostream>
#include <Command.h>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
	Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

	a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
	b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
	c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
	i = new Room("i");

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
bool moveSet;
bool scanSet;
bool tacticalSet;

Command commands[3];
/*
 * commands[0] = moveCommand
 * commands[1] = scanCommand
 * commands[2] = tacticalComand
 **/

void ZorkUL::play() {
    moveSet = false;
    scanSet = false;
    tacticalSet = false;
    printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;


	while (!finished) {
    cout << "Movement command: " ;
        if (!moveSet)
            {
                cout << "not set."<< endl;
            }
     else
        {
         cout << "set."<< endl;
        }

   cout << "Scanning command: " ;
    if (!scanSet)
       {
        cout << "not set."<< endl;
       }
    else
    {
      cout << "set."<< endl;
    }

  cout << "Tactical command: " ;
   if (!tacticalSet)
   {
   cout << "not set."<< endl;
   }
  else {
       cout << "set."<< endl;
   }
        // Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
    if (commandWord.compare("help") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
    {
        if (!moveSet)
        {
            moveSet=true;
        commands[0] = command;

        }
        else cout << "Movement command already set" << endl;
    }

    else if (commandWord.compare("drop") == 0)
        dropItem(command);

    else if (commandWord.compare("scan") == 0)
        {
        if (!scanSet)
        {
            commands[1] = command;
            scanSet=true;
        }
        else cout << "Scanning command already set" << endl;
        }

    else if (commandWord.compare("fire") == 0)
        {
            if (!tacticalSet)
            {
               commands[2] = command;
                tacticalSet = true;
            }
            else cout << "Tactical command already set" << endl;
        }
    else if (commandWord.compare("end") == 0)
       {
        if (moveSet)
        {
            //cout << moveCommand.getSecondWord() << endl;
            goRoom(commands[0]);
        }

        if (tacticalSet)
        {
            useAttack(commands[1]);
        }

        if (scanSet)
        {
            scan(commands[2]);
        }
       moveSet=false;
       scanSet=false;
       tacticalSet=false;
       }

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}

}
void ZorkUL::dropItem(Command command) {
        cout << "Item dropped" <<endl;
        }

void ZorkUL::scan(Command command) {
        cout << "\n...scanning\n" <<endl;
        }

void ZorkUL::useAttack(Command command) {
        cout << "\nAttack used...\n" <<endl;
        }
