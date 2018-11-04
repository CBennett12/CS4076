#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "playerInput.h"



namespace Ui
{
   class MainWindow;
}

class MainWindow : public QMainWindow
{
 Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
