#pragma once
#include "Service.h"

class UIAdmin
{
private:
    Service* servAdmin;

public:
    UIAdmin(Service* servAdmin);

    void startAdmin();
    static void MenuAdmin();

    void addDogRecord();
    void deleteDogRecord();
    void updateDogRecord();
    void displayDogRecord();
};
