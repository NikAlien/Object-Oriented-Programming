#include "Service.h"
#include "../Repo/DynamicArray.h"
#include "../Domain/Offer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Service* createService(Repository *repo, UndoRedo* unre)
{
    /*
        Creates the service
        return: the service
    */
    Service* serv = (Service*)malloc(sizeof(Service));

    if(serv == NULL)
        return NULL;

    serv->repo = repo;
    serv->unre = unre;

    return serv;
}

void destroyService(Service *serv)
{
    /*
        Destroys the service
    */
    if(serv == NULL)
        return;
    
    destroyUnRe(serv->unre);
    destroyRepo(serv->repo);
    free(serv);
}

int addToRepo(Service* serv, char* type, char* dest, char* dep, double price)
{
    /*
        Searches if there is already auch an offer in the repo
        if not:
            creates new offer with given input
            finds the index where it fits according to the price (sorted ascending)
            calls teh add function from repo

        return: 0 if added, -1 if not
    */
    int verification;
    verification = searchOffer(serv->repo, dest, dep);

    if(verification == -1)
    {
        Offer new_of = createOffer(type, dest, dep, price);
        int index = 0;
        while (getPrice(&serv->repo->offers->elems[index]) < price && index < getLength(serv->repo->offers))
        {
            index++;
        }
        
        addOffer(serv->repo, index, new_of);
        return 0;
    }
    return -1;
}

int deleteFromRepo(Service* serv, char* dest, char* dep)
{
    /*
        Searches if this offer exists in repo
        if yes:
            searches the offers index
            calls the delete function from repo

        return: 0 if deleted, -1 if not
    */
    int index = searchOffer(serv->repo, dest, dep);
    if (index == -1)
        return -1;
    deleteOffer(serv->repo, index);
    return 0;
}

int updateOfInfo(Service *serv, char *type, char *dest, char *dep, double price)
{
    /*
        Searches if this offer exists in repo
        if yes:
            searches the offers index
            the offer id deleted and a new one with the updated information is added

        return: 0 if updated, -1 if not
    */
    int index = searchOffer(serv->repo, dest, dep);

    if (index == -1)
        return -1;

    deleteOffer(serv->repo, index);
    addToRepo(serv, type, dest, dep, price);
    return 0;
}

DynamicArray* listDisplay(Service* serv)
{
    /*
        Creates an array with the pointers to the necessary offers to be displayed
        Here: all of them

        return: the pointer to this array
    */
    DynamicArray* da = createArray(1);

    int len = serv->repo->offers->length;

    for(int i = 0; i < len; i++)
        addToPosition(da, serv->repo->offers->elems[i], i);

    return da;
    
}

DynamicArray *listSearchDestination(Service *serv, char *str)
{
    /*
        Creates an array with the pointers to the necessary offers to be displayed
        Here: destination must include the str given at input

        - the str and destination are copied and made lowercase
        - then we look if str is a substring of destination
        - if yes than we add it to the array

        return: the pointer to this array
    */
    DynamicArray* da = createArray(1);
    char dest_repo[30], dest_give[30];
    int len = serv->repo->offers->length;
    int index = 0;

    for(int i = 0; i < strlen(str) - 1; i++)
        dest_give[i] = tolower(str[i]); 
    dest_give[strlen(str) - 1] = '\0';

    for(int i = 0; i < len; i++)
    {
        strcpy(dest_repo, getDest(&serv->repo->offers->elems[i]));
        for(int j = 0; j < strlen(dest_repo); j++)
            dest_repo[j] = tolower(dest_repo[j]); 

        if(strstr(dest_repo, dest_give))
        {
            addToPosition(da, serv->repo->offers->elems[i], index);
            index++;
        }
    }

    return da;
}

DynamicArray *listSearchType(Service *serv, char *type, char *date)
{
    /*
        Creates an array with the pointers to the necessary offers to be displayed
        Here: by specified type and after a given date

        - if given type is same as offer tupe we check the date
        - separate and compare the year
        - if everything okay check case of equal year but comapre months
        - if everything okay check case of equal year, equal months but compare the day

        if correct add to the array

        return: the pointer to this array
    */
    DynamicArray* da = createArray(1);
    char d1[5], m1[5], y1[6];
    char d2[5], m2[5], y2[6], date_repo[15]; 
    int len = serv->repo->offers->length;
    int index = 0;

    d1[0] = date[0]; d1[1] = date[1];
    m1[0] = date[3]; m1[1] = date[4];
    y1[0] = date[6]; y1[1] = date[7]; y1[2] = date[8]; y1[3] = date[9]; 

    for(int i = 0; i < len; i++)
    {
        if(strcmp(getType(&serv->repo->offers->elems[i]), type) == 0)
        {
            strcpy(date_repo, getDepar(&serv->repo->offers->elems[i]));
            d2[0] = date_repo[0]; d2[1] = date_repo[1];
            m2[0] = date_repo[3]; m2[1] = date_repo[4];
            y2[0] = date_repo[6]; y2[1] = date_repo[7]; y2[2] = date_repo[8]; y2[3] = date_repo[9];

            if (strcmp(y2, y1) < 0)
                continue;
            else if (strcmp(y2, y1) == 0 && strcmp(m2, m1) < 0)
                continue;
            else if (strcmp(y2, y1) == 0 && strcmp(m2, m1) == 0 && strcmp(d2, d1) < 0)
                continue;
            
            addToPosition(da, serv->repo->offers->elems[i], index);
            index++;
        }
    }

    return da;
}


void copyRepoServ(Service* serv, UndoRedo* unre)
{   
    /*
        when undo or redo called copy the repo information of the service from the unre 
    */
    // serv->repo->offers->capacity = unre->repos[unre->current_index]->capacity;
    // serv->repo->offers->length = serv->unre->repos[serv->unre->current_index]->length;

    // for(int i = 0; i < serv->unre->repos[serv->unre->current_index]->length; i++)
    //     serv->repo->offers->elems[i] = serv->unre->repos[serv->unre->current_index]->elems[i];

    DynamicArray* da;
    da = copyRepo(unre->repos[unre->current_index]);

    for(int j = 0; j < getLength(serv->repo->offers); j++)
            destroyOffer(&serv->repo->offers->elems[j]);

        destroy(serv->repo->offers);

    serv->repo->offers = da;
    // unre->repos[unre->current_index] = da;
}

int dateValid(char *date)
{   
    /*
        Checks if date is valid
        1. see if format right
        2. separate the day, month and year and check if they are int numbers and respect the norms of the calendar

        return: 0 if invalid, else 1
    */
    if(strlen(date) != 10 || date[2] != '/' || date[5] != '/')
        return 0;
    
    char d[7];
    int ver;
    d[0] = date[0]; d[1] = date[1]; d[2] = '\0';
    ver = atoi(d);
    if(ver < 1 || ver > 31)
        return 0;
    
    d[0] = date[3]; d[1] = date[4]; d[2] = '\0';
    ver = atoi(d);
    if(ver < 1 || ver > 12)
        return 0;

    d[0] = date[6]; d[1] = date[7]; d[2] = date[8]; d[3] = date[9]; d[4] = '\0';
    ver = atoi(d);
    if(ver < 2023 || ver > 2100)
        return 0;

    return 1;
}

int typeValid(char *type)
{   /*
        Checks if type is valid
        see if it corresponds to the 3 available types

        return: 0 if invalid, else 1
    */
    if(strcmp(type, "seaside") == 0)
        return 1;
    
    if(strcmp(type, "city break") == 0)
        return 1;
    
    if(strcmp(type, "mountain") == 0)
        return 1;
    
    return 0;
}