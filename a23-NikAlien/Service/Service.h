#pragma once
#include "../Repo/Repo.h"
#include "../UndoRedo/UndoRedo.h"

typedef struct
{
    Repository* repo;
    UndoRedo* unre;
} Service;

Service* createService(Repository* repo, UndoRedo* unre);
void destroyService(Service* serv);

int addToRepo(Service* serv, char* type, char* dest, char* dep, double price);
int deleteFromRepo(Service* serv, char* dest, char* dep);
int updateOfInfo(Service *serv, char *type, char *dest, char *dep, double price);

DynamicArray* listDisplay(Service* serv);
DynamicArray* listSearchDestination(Service* serv, char* str);
DynamicArray* listSearchType(Service* serv, char* type, char* date);
void copyRepoServ(Service* serv, UndoRedo* unre);
int dateValid(char* date);
int typeValid(char *type);
