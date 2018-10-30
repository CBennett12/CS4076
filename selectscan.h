#ifndef SELECTSCAN_H
#define SELECTSCAN_H

#include <QDialog>
#include <QDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QCoreApplication>
#include <QtGui>
#include <QString>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPixmap>
#include <QLayout>
#include "ZorkUL.h"
#include "mainwindow.h"
#include <QListWidget>

namespace Ui {
class SelectScan;
}

class SelectScan : public QDialog
{
    Q_OBJECT

public:
    explicit SelectScan(QWidget *parent = nullptr);
    ~SelectScan();
    string currentSelected;

private:
    Ui::SelectScan *ui;

};

#endif // SELECTSCAN_H
