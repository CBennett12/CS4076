#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "selectmove.h"
#include "selectscan.h"
#include "selecttact.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ZorkUL game;
    ui->setupUi(this);
    this->setWindowTitle("Subby McSubface");
    //DROP FULL FORWARD
    QPixmap gPic;
    QPixmap rPic;
    rPic.load(":/rec/red.png");
    gPic.load(":/rec/green.png");
    ui->lLabel->setPixmap(rPic);
    ui->lGLabel->setPixmap(gPic);
    ui->mLabel->setPixmap(rPic);
    ui->mGLabel->setPixmap(gPic);
    ui->rLabel->setPixmap(rPic);
    ui->rGLabel->setPixmap(gPic);
    setPixmap();
    //lLabel->show();
    this->setGeometry(
        QRect(
                    QPoint(700, 400),
                    QSize(555, 350))
             );


ui->cBtnLayout->addWidget(ui->lBtn);
ui->cBtnLayout->addWidget(ui->mBtn);
ui->cBtnLayout->addWidget(ui->rBtn);
/*ui->imageLayout->addWidget(lLabel);
ui->imageLayout->addWidget(mLabel);
ui->imageLayout->addWidget(rLabel);*/
//ui->turnLayout->addWidget(gBtn);


     connect(ui->lBtn, SIGNAL (released()), this, SLOT (handlelButton()));
     connect(ui->mBtn, SIGNAL (released()), this, SLOT (handlemButton()));
     connect(ui->rBtn, SIGNAL (released()), this, SLOT (handlerButton()));
     connect(ui->gBtn, SIGNAL (released()), this, SLOT (handlegButton()));
}

MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow:: handlelButton()
{
    selectMove setMovement;
    setMovement.setModal(true);
    setMovement.exec();
    string command;
    int btnSelected;
    btnSelected=setMovement.btnPressed;
    if (btnSelected >= 0)
    {
    command = to_string(btnSelected);
    if (command.compare("")!=0)
    {
     game.setMove(command);
     setPixmap();
    }
    }

}

void MainWindow:: handlemButton()
{
    SelectScan setScanning;
    setScanning.setModal(true);
    setScanning.exec();
    string command;
    command=setScanning.currentSelected;
    game.setScan(command);
    setPixmap();
}

void MainWindow:: handlerButton()
{
    SelectTact setTactical;
    setTactical.setModal(true);
    setTactical.exec();
    string command;
    int btnSelected;
    btnSelected=setTactical.btnPressed;
    command = to_string(btnSelected);
    game.setTact(command);
    setPixmap();
}

void MainWindow:: handlegButton()
{
    QMessageBox messageBox(this);
    messageBox.about(this, "Move", "Executing commands");
    game.resetCommands();
    setPixmap();
    /*ZorkUL temp;
    temp.play();*/
}

void MainWindow:: setPixmap()
{
    if (game.isMoveSet() == false)
    {
        ui->lGLabel->hide();
    }
    else ui->lGLabel->show();
    if (game.isScanSet() == false)
    {
        ui->mGLabel->hide();
    }
    else ui->mGLabel->show();
    if (game.isTactSet() == false)
    {
       ui->rGLabel->hide();
    }
    else ui->rGLabel->show();

}
