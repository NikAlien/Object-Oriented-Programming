#pragma once
#include "../Service/Service.h"

typedef struct
{
    Service* serv;
} UI;

UI* createUi(Service* serv);
void destroyUI(UI* ui);

void start(UI* ui);
void printMenu();
void addDetails(UI* ui);
void deleteDetails(UI* ui);
void updateDetails(UI* ui);
void displaySearch(UI* ui, char* str);
void displayFiltered(UI* ui);
void displayList(UI* ui);
void undoRepo(UI* ui);
void redoRepo(UI* ui);
