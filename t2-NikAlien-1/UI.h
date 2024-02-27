#pragma once
#include "Service.h"

class UI {
private:
    Service* serv;
public:
    UI(Service* s);
    static void printMenu();
    void start();

    void printAll();
};

