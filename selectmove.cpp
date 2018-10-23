#include "selectmove.h"
#include "ui_selectmove.h"
#include "mainwindow.h"

selectMove::selectMove(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectMove)
{
    ui->setupUi(this);
    this->setWindowTitle("Movement");

    QButtonGroup* btnGroup = new QButtonGroup(this);

     btnGroup->addButton(ui->fButton, 0);
     btnGroup->addButton(ui->bButton, 1);
     btnGroup->addButton(ui->lButton, 2);
     btnGroup->addButton(ui->rButton, 3);
     int btnPressed;
     btnPressed=btnGroup->id(btnGroup-> checkedButton());
}

selectMove::~selectMove()
{
    delete ui;
}
