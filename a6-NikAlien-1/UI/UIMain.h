#pragma once
#include "Service/Service.h"

class UI
{
private:
    Service* serv;

public:
    UI(Service* serv);

    void start();
    static void Menu();
    void AdminMonde();
    void UserMode();
};