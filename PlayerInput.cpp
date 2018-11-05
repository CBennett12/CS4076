#include "playerinput.h"
#include "getcommand.h"

std::vector<QLabel*> PlayerInput::map;

PlayerInput::PlayerInput()
{
    size = 10; //global variable
    count = 0;
    QFont font;
    font.setPointSize(12);
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

    tact = new QLabel("Set Tactical Command");
    scan = new QLabel("Set Scanning Command");
    nav = new QLabel("Set Navigation Command");
    tact->setFont(font);
    scan->setFont(font);
    nav->setFont(font);

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
    buttonLayout->setRowStretch(0,-1);
    mainLayout = new QGridLayout(this);
    mainLayout->addLayout(mapLayout, 0, 0, 2, 1);
    mainLayout->addLayout(buttonLayout, 2, 0, Qt::AlignBottom);

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
            setPixmap();
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
            setPixmap();
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

