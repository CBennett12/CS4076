#include "starter.h"
#include "mainwindow.h"
#include "playerInput.h"
#include <QApplication>
#include <iostream>
using namespace std;

const unsigned int global = 10; //Here you go Chris. We found a good use for it. You'll see.
//static const unsigned int halfGlobal;


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow *window = new MainWindow();
    PlayerInput *in = new PlayerInput();
    window->setGeometry(625,250,700,550);
    window->setCentralWidget(in);
    window->show();


    return a.exec();
}
