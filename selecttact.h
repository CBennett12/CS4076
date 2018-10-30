#ifndef SELECTTACT_H
#define SELECTTACT_H

#include <QDialog>
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
#include <QListView>
#include "ZorkUL.h"
#include "mainwindow.h"

namespace Ui {
class SelectTact;
}

class SelectTact : public QDialog
{
    Q_OBJECT

public:
    explicit SelectTact(QWidget *parent = nullptr);
    ~SelectTact();
    int btnPressed;

private:
    Ui::SelectTact *ui;
    QButtonGroup* btnGroup;



};

#endif // SELECTTACT_H
