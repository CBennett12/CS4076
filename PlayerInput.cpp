#include "playerinput.h"
#include "getcommand.h"

std::vector<QLabel*> PlayerInput::map;

PlayerInput::PlayerInput()
{
    size = 10; //global variable
    count = 0;
    cout << "here" << endl;
    moveBtn = new QPushButton("Set Movement Command");
    scanBtn = new QPushButton("Set Scanning Command");
    tactBtn = new QPushButton("Set Tactical Command");
    /*starboard = new QPushButton("Starboard");
    scanAct = new QPushButton("Active Scanning");
    scanPas = new QPushButton("Passive Scanning");
    fireTorp = new QPushButton("Fire Torpedo");
    layMine = new QPushButton("Lay Mine");
    reloadTorp = new QPushButton("Reload Torpedo");
    reloadMine = new QPushButton("Reload Mine");
    salvage = new QPushButton("Salvage");*/

    tact = new QLabel("Set Tactical Commands");
    scan = new QLabel("Set Scan");
    nav = new QLabel("Set Navigation Commands");

    buttonLayout = new QGridLayout();

    buttonLayout->addWidget(nav,0,1);
    buttonLayout->addWidget(moveBtn,1,1);
    /*buttonLayout->addWidget(reverse,3,1);
    buttonLayout->addWidget(port,0,2);
    buttonLayout->addWidget(starboard,0,2);*/

    buttonLayout->addWidget(scan,4,0);
    buttonLayout->addWidget(scanBtn,4,1);
    /*buttonLayout->addWidget(scanPas,4,2);*/

    buttonLayout->addWidget(tact,6,0);
    buttonLayout->addWidget(tactBtn,6,1);
    /*buttonLayout->addWidget(layMine,6,2);
    buttonLayout->addWidget(reloadTorp,7,1);
    buttonLayout->addWidget(reloadMine,7,2);
    buttonLayout->addWidget(salvage,7,3);*/

    mapLayout = new QGridLayout();
    unsigned int index = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            map.push_back(new QLabel(QString::fromStdString(to_string(count))));
            mapLayout->addWidget(map.at(index), i, j);
            cout << index << endl;
            index++;

        }
    }

    mainLayout = new QGridLayout(this);
    mainLayout->addLayout(mapLayout, 0, 0, 2, 1);
    mainLayout->addLayout(buttonLayout, 2, 0);

    setLayout(mainLayout);

    connect(moveBtn, SIGNAL (released()), this, SLOT (handlemButton()));
    connect(scanBtn, SIGNAL (released()), this, SLOT (handlesButton()));
    connect(tactBtn, SIGNAL (released()), this, SLOT (handletButton()));
}

PlayerInput::~PlayerInput()
{

}

void PlayerInput:: handlemButton()
{
    GetCommand setMovement;
    setMovement.setLastSelected("move");
    setMovement.setModal(true);
    setMovement.exec();
    string command;
    int btnSelected;
    btnSelected=setMovement.getBtnPressed();
    cout << command << endl;
    command = to_string(btnSelected);
    if (command.size()>0)
        {
        //game.setMove(command);
        setPixmap();
        }

}

void PlayerInput:: handlesButton()
{
    GetCommand setScanning;
    setScanning.setLastSelected("scan");
    setScanning.setModal(true);
    setScanning.exec();
    string command;
    //command=setScanning.getCurrentSelected();
    cout <<command<<endl;
    if (command.compare("")>0)
    {
        //game.setScan(command);
        setPixmap();
    }
}

void PlayerInput:: handletButton()
{
    GetCommand setTactical;
    setTactical.setLastSelected("scan");
    setTactical.setModal(true);
    setTactical.exec();
    string command;
    int btnSelected;
    btnSelected=setTactical.getBtnPressed();
    command = to_string(btnSelected);
    cout << command << endl;
    if (command.size()>0)
    {
    //game.setTact(command);
    setPixmap();
    }
}

void PlayerInput:: setPixmap()
{
    /*if (!(game.isMoveSet()))
    {
        ui->lGLabel->hide();
    }
    else ui->lGLabel->show();
    if (!(game.isScanSet()))
    {
        ui->mGLabel->hide();
    }
    else ui->mGLabel->show();
    if (!(game.isTactSet()))
    {
       ui->rGLabel->hide();
    }
    else ui->rGLabel->show();
    */

}

