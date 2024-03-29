#include "playerinput.h"
#include "getcommand.h"
#include "starter.h"
#include "game.h"
#include "helpwindow.h"

std::vector<QLabel*> PlayerInput::map;

PlayerInput::PlayerInput()
{
    //create font size for the command labels (makes the labels fit and look nicer)
    QFont font;
    font.setPointSize(10);
    game = new Game();
    //string array for the commands


    //initialise variables for gameplay


    //add buttons to bottom of the screen
    moveBtn = new QPushButton("Set Movement Command");
    scanBtn = new QPushButton("Set Scanning Command");
    tactBtn = new QPushButton("Set Tactical Command");
    helpBtn = new QPushButton("How To Play the Game");
    executeBtn = new QPushButton("Execute Commands");

    //Add the labels for the commands, set font to earliar initialaised font
    tact = new QLabel();
    scan = new QLabel();
    nav = new QLabel();
    help = new QLabel();
    execute = new QLabel();
    tact->setFont(font);
    scan->setFont(font);
    nav->setFont(font);
    help->setFont(font);
    execute->setFont(font);

    //create layout for the buttons, and add each label and button to the layout
    buttonLayout = new QGridLayout();

    buttonLayout->addWidget(nav,0,1, Qt::AlignCenter);
    buttonLayout->addWidget(moveBtn,1,1);

    buttonLayout->addWidget(scan,0,2, Qt::AlignCenter);
    buttonLayout->addWidget(scanBtn,1,2);
    buttonLayout->addWidget(tact,0,3, Qt::AlignCenter);
    buttonLayout->addWidget(tactBtn,1,3);

    buttonLayout->addWidget(executeBtn,2, 2, 2, 1);

    buttonLayout->addWidget(helpBtn,4,2);

    mapLayout = new QGridLayout();
    unsigned int index = 0;
    mapIn = game->map;
    for(unsigned int i = 0; i < global; i++)
    {
        for(unsigned int j = 0; j < global; j++)
        {

            if (mapIn[index]==(nullptr))
            {
                map.push_back(new QLabel("-"));
            }
            else if (mapIn[index]->toString().compare("player") == 0)
            {
                map.push_back(new QLabel("P"));
            }
            /*else if (mapIn[index]->toString().compare("enemy") == 0)
            {
                map.push_back(new QLabel(""));
            }
            else if (mapIn[index]->toString().compare("torpedo") == 0)
            {
                map.push_back(new QLabel(""));
            }
            else if (mapIn[index]->toString().compare("mine") == 0)
            {
                map.push_back(new QLabel(""));
            }
            else if (mapIn[index]->toString().compare("wreck") == 0)
            {
                map.push_back(new QLabel(""));
            }
            */else
            {
                map.push_back(new QLabel(""));
            }

            mapLayout->addWidget(map.at(index),(static_cast<int>(i)),(static_cast<int>(j)));
            index++;
        }
    }

    infoLayout = new QGridLayout();

    //create labels for the information wing, set it to the font, and them to the information layout
    pHealth = new QLabel("Your ships hull strength: ");
    pTorp = new QLabel("Remaining torpedos: ");
    pMine = new QLabel("Remaining mines: ");
    pCode = new QLabel("Pieces of Enigma Code missing: ");
    cHealth = new QLabel(QString::number(game->playerHealth));
    cTorp = new QLabel(QString::number(game->playerTorpedos));
    cMine = new QLabel(QString::number(game->playerMines));
    cCode = new QLabel(QString::number((game->piecesNeeded)));

    pHealth->setFont(font);
    pTorp->setFont(font);
    pMine->setFont(font);
    pHealth->setFont(font);
    infoLayout->addWidget(pHealth, 0, 0, Qt::AlignCenter);
    infoLayout->addWidget(cHealth, 1, 0, Qt::AlignCenter);
    infoLayout->addWidget(pTorp, 0, 1, Qt::AlignCenter);
    infoLayout->addWidget(cTorp, 1, 1, Qt::AlignCenter);
    infoLayout->addWidget(pMine, 0, 2, Qt::AlignCenter);
    infoLayout->addWidget(cMine, 1, 2, Qt::AlignCenter);
    infoLayout->addWidget(pCode, 0, 3, Qt::AlignCenter);
    infoLayout->addWidget(cCode, 1, 3, Qt::AlignCenter);

    //Call the fucntion to set the text in the labels for the commands and information
    updateLabels();

    //Add the 3 layouts to the main layout
    /*
      Map
      Info
      Commands
      */

    buttonLayout->setRowStretch(0,-1);
    mainLayout = new QGridLayout(this);

    mainLayout->addLayout(mapLayout, 0, 0, 2, 1);
    mainLayout->addLayout(infoLayout, 2, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout, 4, 0, Qt::AlignBottom);

    //updateLabels();
    game->populateMap(game->map,game->enemies);
    setLayout(mainLayout);


    //Set the booleans for each command to false


    //slots for each command button
    connect(moveBtn, SIGNAL (released()), this, SLOT (handlemButton()));
    connect(scanBtn, SIGNAL (released()), this, SLOT (handlesButton()));
    connect(tactBtn, SIGNAL (released()), this, SLOT (handletButton()));
    connect(helpBtn, SIGNAL (released()), this, SLOT (handlehButton()));
    connect(executeBtn, SIGNAL(released()), this, SLOT(handleExButton()));



}

PlayerInput::~PlayerInput()
{

}

//Slot for movement button pressed
void PlayerInput:: handlemButton()
{
    //Create a new window for the command "Set movement"
    GetCommand *setMovement = new GetCommand(nullptr, "Movement");
    setMovement->setModal(true);
    setMovement->exec();
    string command;
    int btnSelected=0;
    //If a button is pressed and it is within limits, get its value and save it in the string command
    if (setMovement->getBtnPressed() > 0 && setMovement->getBtnPressed()< 5)
    {
        btnSelected=setMovement->getBtnPressed();
        command = to_string(btnSelected);
        //If something has been saved in command, set movement command and update movement label
        if (command.size()>0)
        {
            game->setCommand(command,0);
            updateLabels();
        }
    }

}

//handler for the scan button
void PlayerInput:: handlesButton()
{
    //create a new window for the command "Set Scan"
    GetCommand *setScanning = new GetCommand(nullptr, "Scanning");
    setScanning->setModal(true);
    setScanning->exec();
    string command;
    int btnSelected=0;
    //if a scan button has been pressed, and it's within the limits, save it to the command string
    if (setScanning->getBtnPressed() > 0 && setScanning->getBtnPressed() < 3)
    {
        btnSelected=setScanning->getBtnPressed();
        command = to_string(btnSelected);
        //if something has been saved in command, add it to the array, and update scanning label
        if (command.size()>0)
        {

            game->setCommand(command, 1);
            updateLabels();
        }
    }
}

//handler for the tactical button
void PlayerInput:: handletButton()
{
    //Create a new window for the command "Set tactical"
    GetCommand *setTactical = new GetCommand(nullptr, "Tactical");
    setTactical->setModal(true);
    setTactical->exec();
    string command;
    int btnSelected=0;

    //if a button has been pressed and is within the limits, get its data and save it to the command string
    if (setTactical->getBtnPressed() > 0 && setTactical->getBtnPressed() < 7)
    {
        btnSelected=setTactical->getBtnPressed();

        command = to_string(btnSelected);
        //if something has been saved to command, add it to the array and update tactical label
        if (command.size()>0)
        {

            if (command.compare("1")==0 && game->getMines()==0)
            {
                QMessageBox messageBox(this);
                messageBox.about(this, "Error", "Insufficient mine ammunition");
            }
            else if ((command.compare("2")==0 || command.compare("3")==0 || command.compare("4")==0 || command.compare("5")==0) && game->getTorps()==0)
            {
                QMessageBox messageBox(this);
                messageBox.about(this, "Error", "Insufficient torpedo ammunition");
            }
            else
            {
                game->setCommand(command, 2);
                updateLabels();
            }
        }
    }
}


//Handler for the execute commands button
void PlayerInput:: handleExButton()
{

    //if each command has been set, execute them
    if ((game->moveSet) || (game->scanSet) || (game->tactSet))
    {
        QMessageBox messageBox(this);
        messageBox.about(this, "Orders Received", "Executing commands");
        if (game->moveSet)
        {
            game->useMove();
        }
        if (game->scanSet)
        {
            game->useScan();
        }
        if (game->tactSet)
        {
            game->useAttack();
        }
        //When all commands have been executed, reset them and update the labels
        updateLabels();
        updateMapLabels();
        game->resetCommands();
    }
    else
    {
        QMessageBox messageBox(this);
        messageBox.about(this, "Error", "No Command Set");
    }

}


void PlayerInput:: handlehButton()
{
    HelpWindow *setHelp = new HelpWindow();
    setHelp->setModal(true);
    setHelp->exec();

}


void PlayerInput:: updateLabels()
{

    mapIn=game->map;
    //If each command is or isn't set, set the labels accordingly
    if (!(game->moveSet))
    {
        nav->setText("Navigation Command Not Set");
    }
    else
    {
        nav->setText("Navigation Command Set");
    }
    if (!(game->scanSet))
    {
        scan->setText("Scanning Command Not Set");
    }
    else
    {
        scan->setText("Scanning Command Set");
    }
    if (!(game->tactSet))
    {
        tact->setText("Tactical Command Not Set");
    }
    else
    {
        tact->setText("Tactical Command Set");
    }
    //Set labels for health, torpedos, mines and enigma codes
    cHealth->setText(QString::number(game->playerHealth));
    cTorp->setText(QString::number(game->playerTorpedos));
    cMine->setText(QString::number(game->playerMines));
    cCode->setText(QString::number((game->piecesNeeded)));



    /*mapLayout->update();
    mainLayout->addLayout(mapLayout, 0, 0, 2, 1);
    mainLayout->update();*/
    checkGameOver(game);

}

void PlayerInput::checkGameOver(Game* game)
{
    //Victory
    if (game->piecesNeeded == 0)
    {
        QMessageBox messageBox(this);
        messageBox.about(this, "Congradulation", "All pieces collected, plan successful\n \\(^o^)/  \\(^0^)/  \\(^o^)/  \\(^0^)/");
        this->setDisabled(true);
        this->close();
    }

    //Defeat
    if (game->playerHealth == 0)
    {
        QMessageBox messageBox(this);
        messageBox.about(this, "Comiseration", "Submarine has been compromised, plan unsuccessful\n /(XoX)\\");
        this->setDisabled(true);
        this->close();
    }
}

void PlayerInput::updateMapLabels()
{
    /*
    for (int k = 0; k< static_cast<int>(map.size());k++)
    {
        map.at(k)->clear();
    }*/
    //mainLayout->removeItem(mapLayout);
    for (int j = 0; j< static_cast<int>(map.size());j++)
    {
        map.at(j)->clear();
        if (mapIn[j]==(nullptr))
        {
            map.at(j)->setText("-");
        }
        else if (mapIn[j]->toString().compare("player") == 0)
        {
            map.at(j)->setText("P");
        }
        else if (game->map[j]->toString().compare("enemy") == 0)
        {
            map.at(j)->setText(("E"));
        }
        else if (mapIn[j]->toString().compare("torpedo") == 0)
        {
            map.at(j)->setText("T");
        }
        else if (mapIn[j]->toString().compare("mine") == 0)
        {
            map.at(j)->setText("M");
        }
        else if (mapIn[j]->toString().compare("wreck") == 0)
        {
            map.at(j)->setText("W");
        }
        else
        {
            map.at(j)->setText("");
        }
    }
}



