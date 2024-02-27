#pragma once
#include "Service.h"

class UIUser
{
private:
    Service* servUser;

public:
    UIUser(Service* serv);

    void startUser();
    static void MenuUser();
    static void slideShowPrint(const Dog* d);

    void lookAtDogs();
    void searchForDog();
    void displayAdoptionList();
    void displayFile();
    void saveListFile();

    void slideShow(std::vector<Dog*>* dogList);
};