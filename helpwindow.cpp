#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Help");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QTextBrowser* tBrow = new QTextBrowser();
    QFont font;
    font.setPointSize(12);
QVBoxLayout* textLayout = new QVBoxLayout(this);
tBrow->setFont(font);
tBrow->setText("Your mission, should you choose to accept it, is to retrieve pieces of the enigma code.\n\n"
               "The mission will not be easy, and you will face obstacles in your path trying to stop you."
               "We have narrowed the search to a small piece of the ocean, and have provided you with the latest in sea scanning technology."
               "Tactical resources are limited, and therefore we have to cap the amount of mines and torpedos we can provide you with, "
               "however we have intelligence that any enemy ships in the AO will also carry these weapons.\n"
               "Good luck");
textLayout->addWidget(tBrow);
textLayout->addWidget(ui->buttonBox);
setLayout(textLayout);

}

HelpWindow::~HelpWindow()
{
    delete ui;
}
