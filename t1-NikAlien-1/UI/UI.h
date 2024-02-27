#pragma once
#include "Service/Serv.h"
#include "Domain/Protein.h"

class UI {

private:
    Serv* service;
public:
    UI(Serv* serv);

    void start();
    void displayAll();
    void removeProtein();
    void searchProtein();
    static void printMenu();

};

