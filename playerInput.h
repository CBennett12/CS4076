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


           bool moveSet;
           bool scanSet;
           bool tactSet;
           string commands[3];
           void setMove(string command);
           void setScan(string command);
           void setTact(string command);
           void resetCommands();

    private:
        QPushButton *moveBtn, *scanBtn, *tactBtn, *helpBtn, *executeBtn;
        QLabel *tact, *scan, *nav, *temp, *help, *pHealth, *pTorp, *pMine, *pCode, *execute, *cHealth, *cTorp, *cMine, *cCode;
        int count, playerHealth, playerTorpedos, playerMines, playerCodes, maxHealth, maxTorpedos, maxMines, piecesNeeded;
        QGridLayout *mainLayout, *buttonLayout, *mapLayout, *infoLayout;
        Room *currentRoom;

        static vector<QLabel*>map;
        QFont font;
        QPixmap rPic;
        QPixmap gPic;
        void useScan(string command);
        void useAttack(string command);
        void useMove(string command);
        void checkGameOver();



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
