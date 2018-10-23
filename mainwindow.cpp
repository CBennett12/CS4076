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
    //gBtn = new QPushButton("End turn", this);
    //QLabel* lLabel = new QLabel(this);
    QLabel* tLabel = new QLabel(this);
    tLabel->setGeometry(60, 25, 100, 100);
    cout << game.isMoveSet();
    if (game.isMoveSet() == false)
    {
    ui->lLabel->setPixmap(rPic);
    }
    else ui->lLabel->setPixmap(gPic);
    //QLabel* mLabel = new QLabel(this);
    //mLabel->setGeometry(225, 25, 100, 100);
    if (game.isScanSet() == false)
    {
        ui->mLabel->setPixmap(rPic);
    }
    else ui->mLabel->setPixmap(gPic);
    //QLabel* rLabel = new QLabel(this);
    //rLabel->setGeometry(400, 25, 100, 100);
    if (game.isTactSet() == false)
    {
        ui->rLabel->setPixmap(rPic);
    }
    else ui->rLabel->setPixmap(gPic);
    //lLabel->show();
    this->setGeometry(
        QRect(
                    QPoint(700, 400),
                    QSize(555, 350))
             );
   /* lBtn->setGeometry(
        QRect(
                    QPoint(30, 200),
                    QSize(150, 50))
             );
    mBtn->setGeometry(
        QRect(
                    QPoint(205, 200),
                    QSize(150, 50))
             );
    rBtn->setGeometry(
        QRect(
                    QPoint(380, 200),
                    QSize(150, 50))
             );
    gBtn->setGeometry(
        QRect(
                    QPoint(205, 275),
                    QSize(150, 50))
             );*/
tLabel->setPixmap(gPic);
tLabel->hide();
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
        //lLabel->hide();
    changePixmap(tLabel);

    game.setMove(command);
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
}

void MainWindow:: handlerButton()
{
    SelectTact setTactical;
    setTactical.setModal(true);
    setTactical.exec();
    string command;
    int btnSelected;
    btnSelected=setTactical.btnPressed;
    if (btnSelected >= 0)
    {
    command = to_string(btnSelected);
    //command=setScanning.btnPressed;
    game.setTact(command);
    }
}

void MainWindow:: handlegButton()
{
    QMessageBox messageBox(this);
    messageBox.about(this, "Move", "Commands Set");
    /*ZorkUL temp;
    temp.play();*/
}

void MainWindow:: changePixmap(QLabel* image)
{
    //rPic.load(":/rec/green.png");
    //image->show();
    //ui->imageLayout->update();
    //image->setVisible(false);

}
