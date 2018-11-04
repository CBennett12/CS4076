#include "playerinput.h"

std::vector<QLabel*> PlayerInput::map;

PlayerInput::PlayerInput()
{
    size = 10; //global variable
    count = 0;
    cout << "here" << endl;
    forward = new QPushButton("Forward");
    reverse = new QPushButton("Reverse");
    port = new QPushButton("Port");
    starboard = new QPushButton("Starboard");
    scanAct = new QPushButton("Active Scanning");
    scanPas = new QPushButton("Passive Scanning");
    fireTorp = new QPushButton("Fire Torpedo");
    layMine = new QPushButton("Lay Mine");
    reloadTorp = new QPushButton("Reload Torpedo");
    reloadMine = new QPushButton("Reload Mine");
    salvage = new QPushButton("Salvage");

    tact = new QLabel("Tactical Commands");
    scan = new QLabel("Scan");
    nav = new QLabel("Navigation Commands");

    buttonLayout = new QGridLayout();

    buttonLayout->addWidget(nav,0,1);
    buttonLayout->addWidget(forward,1,1);
    buttonLayout->addWidget(reverse,3,1);
    buttonLayout->addWidget(port,0,2);
    buttonLayout->addWidget(starboard,0,2);

    buttonLayout->addWidget(scan,4,0);
    buttonLayout->addWidget(scanAct,4,1);
    buttonLayout->addWidget(scanPas,4,2);

    buttonLayout->addWidget(tact,6,0);
    buttonLayout->addWidget(fireTorp,6,1);
    buttonLayout->addWidget(layMine,6,2);
    buttonLayout->addWidget(reloadTorp,7,1);
    buttonLayout->addWidget(reloadMine,7,2);
    buttonLayout->addWidget(salvage,7,3);

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
}

PlayerInput::~PlayerInput()
{

}
