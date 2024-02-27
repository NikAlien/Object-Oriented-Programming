#include "gui.h"
#include "BacteriaModel.h"
#include "RepoBiologist.h"
#include "RepoBacteria.h"
#include "iostream"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RepoBiologist rb;
    RepoBacteria rbac;
    Service serv(rbac, rb);
    BacteriaModel bm(serv);
    std::vector<GUI*> vect;

    for(auto bio : rb.getList())
    {
        vect.push_back(new GUI(serv, bm, bio));
    }
    for(auto g: vect)
    {
        g->show();
    }
    return a.exec();
}
