#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handlelButton();
    void handlemButton();
    void handlerButton();
    void handlegButton();
    void changePixmap(QLabel* image);

private:
    Ui::MainWindow *ui;
    QPixmap gPic;
    QPixmap rPic;
    QLabel* tLabel;
    QPushButton* setDir;
    QPushButton* setScn;
    QPushButton* setTac;
    QButtonGroup* btnGroup;
    QRadioButton* fButton;
    QRadioButton* bButton;
    QRadioButton* lButton;
    QRadioButton* rButton;
    QLabel* label;
    //QDialog* movePopup;
    QDialog* scanPopup;
    QDialog* tactPopup;
    int btnSelected;
    ZorkUL game;
    string command;
};

#endif // MAINWINDOW_H
