#include "selecttact.h"
#include "ui_selecttact.h"

SelectTact::SelectTact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectTact)
{
    ui->setupUi(this);
    this->setWindowTitle("Tactical");
    QButtonGroup* btnGroup = new QButtonGroup(this);



     btnGroup->addButton(ui->mButton, 0);
     btnGroup->addButton(ui->tButton, 1);
     int btnPressed=-1;
     btnPressed=btnGroup->id(btnGroup-> checkedButton());
}

SelectTact::~SelectTact()
{
    delete ui;
}
