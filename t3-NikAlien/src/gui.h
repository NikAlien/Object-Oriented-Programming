#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include "serv.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(Service* s, QWidget *parent = nullptr);
    ~GUI();

private:
    Ui::GUI *ui;
    Service* serv;

    void displayList();
    void signSlot();
    void filter();
    void matching();
};
#endif // GUI_H
