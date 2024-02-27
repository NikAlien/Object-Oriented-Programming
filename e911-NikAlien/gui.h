#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include "BacteriaModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(Service& serv, BacteriaModel& b, Biologist& bio, QWidget *parent = nullptr);
    ~GUI();

private:
    Ui::GUI *ui;
    BacteriaModel& model;
    Biologist& biol;
    Service& serv;

    void filter();
    void signSlot();
    void populateList();
    void add();

};
#endif // GUI_H
