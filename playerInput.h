#ifndef PlayerInput_H
#define PlayerInput_H


#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextStream>
#include <QLabel>
#include <QString>
#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

class PlayerInput : public QWidget
{
    Q_OBJECT

    public:
       explicit PlayerInput();
       ~PlayerInput();
       void setRoom(Room holder);
       string getCurrentRoom();
       int size; //Global Variable

    private:
        QPushButton *moveBtn, *scanBtn, *tactBtn;
        QLabel *tact, *scan, *nav, *temp;
        QGridLayout *mainLayout, *buttonLayout, *mapLayout;
        Room *currentRoom;
        int count;
        static vector<QLabel*>map;

    /*private slots:
        void navForward();
        void navReverse();
        void navPort();
        void navStarboard();
        void scanActive();
        void scanPassive();
        void tactFireTorpedo();
        void tactLayMine();
        void tactReloadTorpedo();
        void tactReloadMine();
        void tactSalvage();*/

private slots:
    void handlemButton();
    void handlesButton();
    void handletButton();
    void setPixmap();
};
#endif // PlayerInput_H
