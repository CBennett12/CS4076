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
#include "starter.h"
#include "ship.h"
#include "game.h"
using namespace std;

class PlayerInput : public QWidget
{
    Q_OBJECT

    public:
       explicit PlayerInput();
       ~PlayerInput();
       void setRoom(Room);
       string getCurrentRoom();
       int size; //Global Variable

       void resetCommands();
       void update();

    private:
        QPushButton *moveBtn, *scanBtn, *tactBtn, *helpBtn, *executeBtn;
        QLabel *tact, *scan, *nav, *temp, *help, *pHealth, *pTorp, *pMine, *pCode, *execute, *cHealth, *cTorp, *cMine, *cCode;
        int count;
        QGridLayout *mainLayout, *buttonLayout, *mapLayout, *infoLayout;
        Room *currentRoom;
        Game* game;

        static vector<QLabel*>map;
        QFont font;
        QPixmap rPic;
        QPixmap gPic;
        void useScan(string command);
        void useAttack(string command);
        void useMove(string command);
        void checkGameOver(Game* game);
        void updateMap(Room[]);
        //void updateValues(uno[]);
        //can't do an array of abstract class
        void updateUI();

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
    void handleExButton();
    //void handlehButton();
    //void handleeButton();


    void changePixmap();
};
#endif // PlayerInput_H
