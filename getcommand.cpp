#include "getcommand.h"
#include "ui_getcommand.h"
#include "playerInput.h"

GetCommand::GetCommand(QWidget *parent, string lastSelected) :
    QDialog(parent),
    ui(new Ui::GetCommand)
{
    ui->setupUi(this);
    string title ="Get " + lastSelected + " Command";
    this->setWindowTitle(QString::fromStdString(title));

   //Create a button group for the different commands
    QButtonGroup* btnGroup = new QButtonGroup(this);
    QVBoxLayout* buttonsLayout = new QVBoxLayout(this);
    buttonsLayout->setSpacing(0);
    //string lastSelected="move";
    string cList [5];
    //int btnPressed=-1;
    btn1 = new QRadioButton("Button1");
    btn2 = new QRadioButton("Button2");
    btn3 = new QRadioButton("Button3");
    btn4 = new QRadioButton("Button4");
    btn5 = new QRadioButton("Button5");

    //If you are setting movement command, set 4 buttons, hide 1
    if (lastSelected.compare("Movement")==0)
    {
        isMove(cList);

        btn1->setText(QString::fromStdString(cList[0]));
        btn2->setText(QString::fromStdString(cList[1]));
        btn3->setText(QString::fromStdString(cList[2]));
        btn4->setText(QString::fromStdString(cList[3]));
        btn1->show();
        btn2->show();
        btn3->show();
        btn4->show();
        btn5->hide();
    }
    //If you are setting scanning command, set 2 buttons, hide 3
    else if (lastSelected.compare("Scanning")==0)
    {
        isScan(cList);
        btn1->setText(QString::fromStdString(cList[0]));
        btn2->setText(QString::fromStdString(cList[1]));
        btn1->show();
        btn2->show();
        btn3->hide();
        btn4->hide();
        btn5->hide();
    }
    //If you are setting tactical command, set all 5 buttons
    else if (lastSelected.compare("Tactical")==0)
    {
        isTact(cList);
        btn1->setText(QString::fromStdString(cList[0]));
        btn2->setText(QString::fromStdString(cList[1]));
        btn3->setText(QString::fromStdString(cList[2]));
        btn4->setText(QString::fromStdString(cList[3]));
        btn5->setText(QString::fromStdString(cList[4]));
        btn1->show();
        btn2->show();
        btn3->show();
        btn4->show();
        btn5->show();
    }
    //Add the 5 buttons to the button group, and the button layout
    btnGroup->addButton(btn1, 1);
    btnGroup->addButton(btn2, 2);
    btnGroup->addButton(btn3, 3);
    btnGroup->addButton(btn4, 4);
    btnGroup->addButton(btn5, 5);
    buttonsLayout->addWidget(btn1);
    buttonsLayout->addWidget(btn2);
    buttonsLayout->addWidget(btn3);
    buttonsLayout->addWidget(btn4);
    buttonsLayout->addWidget(btn5);
    buttonsLayout->addWidget(ui->buttonBox);


    buttonsLayout->setSpacing(0);

    buttonsLayout->setMargin(3);
    setLayout(buttonsLayout);

    //Slots for if ok button or cancel button is pressed
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(cancelPressed()));
    connect(btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonWasClicked(int)));

}

GetCommand::~GetCommand()
{
    delete ui;
}

//If selecting movement command, set list of commands to the movement list
void GetCommand:: isMove(string cList[5])
{
    cList[0]="Go Forward";
    cList[1]="Go Backward";
    cList[2]="Turn Port";
    cList[3]="Turn Starboard";
    cList[4]="";

}

//If selecting Scanning command, set list of commands to the scanning list
void GetCommand:: isScan(string cList[5])
{
    cList[0]="Passive Scanning";
    cList[1]="Active Scanning";
    cList[2]="";
    cList[3]="";
    cList[4]="";

}


//If selecting tactical command, set list of commands to the tactical list
void GetCommand:: isTact(string cList[5])
{
    cList[0]="Reload Torpedo";
    cList[1]="Reload Mine";
    cList[2]="Lay Mine";
    cList[3]="Fire Torpedo";
    cList[4]="Salvage";

}

//save the index of the button pressed
void GetCommand:: setBtnInt(int temp)
{
    btnPressed = temp;
}

//Cancel button pressed, returning 0, previous command saved
void GetCommand:: cancelPressed()
{
    btnPressed = 0;
}

int GetCommand:: getBtnPressed() const
{
    return btnPressed;
}


void GetCommand::buttonWasClicked(int buttonID)
{
   btnPressed = buttonID;
}

//Sets the type of commadn we are setting
void GetCommand:: setLastSelected(string temp)
{
    lastSelected=temp;
}
