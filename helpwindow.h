#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>
#include <qlabel.h>
#include <string>
#include <QLayout>
#include <qtextbrowser.h>
using std::string;

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
