#ifndef GETCOMMAND_H
#define GETCOMMAND_H

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
#include "mainwindow.h"

namespace Ui {
class GetCommand;
}

class GetCommand : public QDialog
{
    Q_OBJECT

public:
    explicit GetCommand(QWidget *parent = nullptr);
    ~GetCommand();

    string lastSelected;
    int btnPressed;
    int getBtnPressed() const;
    void isMove(string []);
    void isScan(string []);
    void isTact(string []);
    void setBtnInt(int temp);
    void setLastSelected(string temp);

private:
    Ui::GetCommand *ui;
    QButtonGroup* btnGroup;
    QPushButton *btn1, *btn2, *btn3, *btn4, *btn5;

private slots:
    void changeBtnPressed(QAbstractButton* btn, int temp);
};

#endif // GETCOMMAND_H
