#include "CommandWords.h"

vector<string> CommandWords::validCommands;

/**
 * Constructor - initialise the command words.
 */
CommandWords::CommandWords() {
	// Populate the vector if we haven't already.
    if (validCommands.empty())
    {
        //Navigation Commands
        validCommands.push_back("turn"); //either port/starboard or cardinal
        validCommands.push_back("ahead"); //either full for 2 movements, or 1 movement
        validCommands.push_back("reverse"); //either full for 2 movements, or 1 movement

        //Tactical Commands
        validCommands.push_back("drop"); //sea mine
        validCommands.push_back("fire"); //torpedo
        validCommands.push_back("reload"); //either torpedo or mine
        validCommands.push_back("use"); //interact with object

        //Scanning Commands
        validCommands.push_back("scan"); //either active or passive
        validCommands.push_back("map");

        //Base Commands
        validCommands.push_back("end"); //ends turn
        validCommands.push_back("quit");
        validCommands.push_back("help");

        //Commands not being used
        //validCommands.push_back("go");
        //validCommands.push_back("take");
        //validCommands.push_back("put");

	}
}

/**
 * Check whether a given String is a valid command word.
 * Return true if it is, false if it isn't.
 **/
bool CommandWords::isCommand(string aString) {
	for (unsigned int i = 0; i < validCommands.size(); i++)
	{
		if (validCommands[i].compare(aString) == 0)
			return true;
	}
	// if we get here, the string was not found in the commands
	return false;
}

/*
 * Print all valid commands to System.out.
 */
void CommandWords::showAll() {
	//Loops through validCommands and prints each to the screen.
	for (unsigned int i = 0; i < validCommands.size(); i++)
	{
		cout << validCommands[i]<< "  ";
	}
	cout << endl;
}
