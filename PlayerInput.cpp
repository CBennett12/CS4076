#include "playerinput.h"
#include "getcommand.h"

std::vector<QLabel*> PlayerInput::map;

PlayerInput::PlayerInput()
{
    QFont font;
    font.setPointSize(10);
    
    moveBtn = new QPushButton("Set Movement Command");
    scanBtn = new QPushButton("Set Scanning Command");
    tactBtn = new QPushButton("Set Tactical Command");
    helpBtn = new QPushButton("How To Play the Game");
    executeBtn = new QPushButton("Execute Commands");

    /*starboard = new QPushButton("Starboard");
    scanAct = new QPushButton("Active Scanning");
    scanPas = new QPushButton("Passive Scanning");
    fireTorp = new QPushButton("Fire Torpedo");
    layMine = new QPushButton("Lay Mine");
    reloadTorp = new QPushButton("Reload Torpedo");
    reloadMine = new QPushButton("Reload Mine");
    salvage = new QPushButton("Salvage");*/

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
    changePixmap();


    buttonLayout = new QGridLayout();

    buttonLayout->addWidget(nav,0,1, Qt::AlignCenter);
    buttonLayout->addWidget(moveBtn,1,1);
    /*buttonLayout->addWidget(reverse,3,1);
    buttonLayout->addWidget(port,0,2);
    buttonLayout->addWidget(starboard,0,2);*/

    buttonLayout->addWidget(scan,0,2, Qt::AlignCenter);
    buttonLayout->addWidget(scanBtn,1,2);
    /*buttonLayout->addWidget(scanPas,4,2);*/

    buttonLayout->addWidget(tact,0,3, Qt::AlignCenter);
    buttonLayout->addWidget(tactBtn,1,3);
    /*buttonLayout->addWidget(layMine,6,2);
    buttonLayout->addWidget(reloadTorp,7,1);
    buttonLayout->addWidget(reloadMine,7,2);
    buttonLayout->addWidget(salvage,7,3);*/

    buttonLayout->addWidget(execute,1,2, Qt::AlignCenter);
    buttonLayout->addWidget(executeBtn,2,2);

    buttonLayout->addWidget(help,3,2, Qt::AlignCenter);
    buttonLayout->addWidget(helpBtn,4,2);

    mapLayout = new QGridLayout();
    //unsigned int index = 0;


    for(unsigned int i = 0; i < global; i++)
    {
        for(unsigned int j = 0; j < global; j++)
        {
            map.push_back(new QLabel(QString::fromStdString(to_string(i*10 + j))));
            mapLayout->addWidget(map.at(i*10 + j), i, j);
            cout << i*10 + j << endl;
            //index++;
            Room tempRoom(i*10 + j);
        }
    }

    infoLayout = new QGridLayout();

    //Change later:
    playerHealth = 5;
    playerTorpedos = 5;
    playerMines = 3;
    playerCodes = 0;

    pHealth = new QLabel("Your ships hull strength: ");
    pTorp = new QLabel("Remaining torpedos: ");
    pMine = new QLabel("Remaining mines: ");
    pCode = new QLabel("Pieces of Enigma Code missing: ");
    cHealth = new QLabel((QString::fromStdString(to_string(playerHealth))));
    cTorp = new QLabel((QString::fromStdString(to_string(playerTorpedos))));
    cMine = new QLabel((QString::fromStdString(to_string(playerMines))));
    cCode = new QLabel((QString::fromStdString(to_string(playerCodes))));

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

    buttonLayout->setRowStretch(0,-1);
    mainLayout = new QGridLayout(this);
    mainLayout->addLayout(mapLayout, 0, 0, 2, 1);
    mainLayout->addLayout(infoLayout, 2, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout, 4, 0, Qt::AlignBottom);

    setLayout(mainLayout);

    connect(moveBtn, SIGNAL (released()), this, SLOT (handlemButton()));
    connect(scanBtn, SIGNAL (released()), this, SLOT (handlesButton()));
    //connect(tactBtn, SIGNAL (released()), this, SLOT (handletButton()));
    //connect(helpBtn, SIGNAL (released()), this, SLOT (handlehButton()));
}

PlayerInput::~PlayerInput()
{

}

void PlayerInput:: handlemButton()
{
    GetCommand *setMovement = new GetCommand(nullptr, "move");
    setMovement->setModal(true);
    setMovement->exec();
    string command;
    int btnSelected=0;
    if (setMovement->getBtnPressed() > 0 && setMovement->getBtnPressed()< 5)
    {
        btnSelected=setMovement->getBtnPressed();
    }
        command = to_string(btnSelected);
        cout << command << endl;
        if (command.size()>0)
            {
            //game.setMove(command);
            changePixmap();
            }

}

void PlayerInput:: handlesButton()
{
    GetCommand *setScanning = new GetCommand(nullptr, "scan");
    setScanning->setModal(true);
    setScanning->exec();
    string command;
    int btnSelected=0;
    if (setScanning->getBtnPressed() > 0 && setScanning->getBtnPressed() < 3)
    {
        btnSelected=setScanning->getBtnPressed();
    }
        command = to_string(btnSelected);
        cout << command << endl;
        if (command.size()>0)
        {

            //game.setScan(command);
            changePixmap();
        }
}

void PlayerInput:: handletButton()
{
    GetCommand *setTactical = new GetCommand(nullptr, "tact");
    setTactical->setModal(true);
    setTactical->exec();
    string command;
    int btnSelected=0;
    if (setTactical->getBtnPressed() > 0 && setTactical->getBtnPressed() < 6)
    {
        btnSelected=setTactical->getBtnPressed();
    }
        command = to_string(btnSelected);
        cout << command << endl;
        if (command.size()>0)
        {
            //game.setTact(command);
            changePixmap();
        }
}


/*
void PlayerInput:: handlehButton()
{
    GetCommand *setHelp = new GetCommand(nullptr, "help");

}
*/

void PlayerInput:: changePixmap()
{
    if (!(/*game.isMoveSet()*/0))
    {
        nav->setText("Navigation Command Not Set");
    }
    else  nav->setText("Navigation Command Set");
    if (!(/*game.isScanSet()*/0))
    {
        scan->setText("Scanning Command Not Set");
    }
    else scan->setText("Scanning Command Set");
    if (!(/*game.isTactSet()*/0))
    {
       tact->setText("Tactical Command Not Set");
    }
    else tact->setText("Tactical Command Set");


}

