#include "gui.h"
#include "repo.h"
#include "serv.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Repository r;
    Service s(&r);
    QApplication a(argc, argv);
    GUI w(&s);
    w.show();
    return a.exec();

}
