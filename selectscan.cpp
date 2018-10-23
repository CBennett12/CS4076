#include "selectscan.h"
#include "ui_selectscan.h"

SelectScan::SelectScan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectScan)
{
    ui->setupUi(this);
    this->setWindowTitle("Scanning");
    QString temp;
    string currentSelected;
    if (ui->listofScans->currentItem() != NULL)
    {
    temp =ui->listofScans->currentItem()->text();
    currentSelected = (temp.toStdString());
    }

}

SelectScan::~SelectScan()
{
    delete ui;



}
