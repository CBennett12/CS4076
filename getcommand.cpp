#include "getcommand.h"
#include "ui_getcommand.h"
#include "playerInput.h"

GetCommand::GetCommand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetCommand)
{
    ui->setupUi(this);
    this->setWindowTitle("Get Command");

    QButtonGroup* btnGroup = new QButtonGroup(this);
    QVBoxLayout* buttonsLayout = new QVBoxLayout(this);

    string lastSelected="";
    string cList [5];
    int btnSelected;
    btn1 = new QPushButton("Button1");
    btn2 = new QPushButton("Button2");
    btn3 = new QPushButton("Button3");
    btn4 = new QPushButton("Button4");
    btn5 = new QPushButton("Button5");

    btnGroup->addButton(btn1, 0);
    btnGroup->addButton(btn2, 1);
    btnGroup->addButton(btn3, 2);
    btnGroup->addButton(btn4, 3);
    btnGroup->addButton(btn5, 4);
    buttonsLayout->addWidget(btn1);
    buttonsLayout->addWidget(btn2);
    buttonsLayout->addWidget(btn3);
    buttonsLayout->addWidget(btn4);
    buttonsLayout->addWidget(btn5);
    btn1->show();
    btn2->show();
    btn3->show();
    btn4->show();
    btn5->show();

    if (lastSelected.compare("move")==0)
    {
        isMove(cList);

        btn1->setText(QString::fromStdString(cList[0]));
        btn2->setText(QString::fromStdString(cList[1]));
        btn3->setText(QString::fromStdString(cList[2]));
        btn4->setText(QString::fromStdString(cList[3]));
        btn5->hide();
    }
    else if (lastSelected.compare("scan")==0)
    {
        isScan(cList);
        btn1->setText(QString::fromStdString(cList[0]));
        btn2->setText(QString::fromStdString(cList[1]));
        btn3->hide();
        btn4->hide();
        btn5->hide();
    }
    else if (lastSelected.compare("tact")==0)
    {
        isTact(cList);
        btn1->setText(QString::fromStdString(cList[0]));
        btn2->setText(QString::fromStdString(cList[1]));
        btn3->setText(QString::fromStdString(cList[2]));
        btn4->setText(QString::fromStdString(cList[3]));
        btn5->setText(QString::fromStdString(cList[4]));
    }


    connect(btnGroup, SIGNAL(buttonClicked(QAbstractButton*)),
                                 this, SLOT(changeBtnPressed(QAbstractButton* btn, int temp)));

}

GetCommand::~GetCommand()
{
    delete ui;
}

void GetCommand:: isMove(string cList[5])
{
    cList[0]="Go Forward";
    cList[1]="Go Backward";
    cList[2]="Go Port";
    cList[3]="Go Starboard";
    cList[4]="";

}

void GetCommand:: isScan(string cList[5])
{
    cList[0]="Passive Scanning";
    cList[1]="Active Scanning";
    cList[2]="";
    cList[3]="";
    cList[4]="";

}

void GetCommand:: isTact(string cList[5])
{
    cList[0]="Reload Torpedo";
    cList[1]="Reload Mine";
    cList[2]="Lay Mine";
    cList[3]="Fire Torpedo";
    cList[4]="Salvage";

}

void GetCommand:: setBtnInt(int temp)
{
    btnPressed = temp;
}

int GetCommand:: getBtnPressed() const
{
    return btnPressed;
}

void GetCommand:: changeBtnPressed(QAbstractButton* btn, int temp)
{
       temp=btnGroup->id(btn);
       setBtnInt(temp);
       cout << btnPressed << endl;
}

void GetCommand:: setLastSelected(string temp)
{
    lastSelected=temp;
}
