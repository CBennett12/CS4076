#ifndef SELECTMOVE_H
#define SELECTMOVE_H

#include <QDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QCoreApplication>
#include <QtGui>
#include <QLabel>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPixmap>
#include <QLayout>
#include "ZorkUL.h"
#include "mainwindow.h"
namespace Ui {
class selectMove;
}

class selectMove : public QDialog
{
    Q_OBJECT

public:
    explicit selectMove(QWidget *parent = nullptr);
    ~selectMove();
    int btnPressed;


private:
    Ui::selectMove *ui;
    QButtonGroup* btnGroup;

};

#endif // SELECTMOVE_H
