#include "Repo.h"
#include <stdlib.h>
#include <string.h>

Repository* createRepo(DynamicArray* arr)
{
    /*
        Creates a repository
        return: the repository
    */
    Repository* repo = (Repository*)malloc(sizeof(Repository));

    if(repo == NULL)
        return NULL;

    repo->offers = arr;

    return repo;
}

void destroyRepo(Repository* repo)
{
    /*
        Destroys the repository
    */
    if(repo == NULL)
        return;
    
    for(int index = 0; index < getLength(repo->offers); index++)
        destroyOffer(&repo->offers->elems[index]);

    destroy(repo->offers);
    free(repo);
}

void addOffer(Repository* repo, int index, Offer of)
{
    /*
        calls the function add from dynamic array to add element to a position
    */
    addToPosition(repo->offers, of, index);
}

int searchOffer(Repository *repo, char* dest, char *date)
{
    /*
        Destination and departue date are unique for every offer
        We look for a specific offer in the repository with the given destination and date

        return: -1 if not found; if found its index
    */
    int index = 0;
    while (index < getLength(repo->offers))
    {
        if(strcmp(getDest(&repo->offers->elems[index]), dest) == 0 && strcmp(getDepar(&repo->offers->elems[index]), date) == 0)
            return index;
        index++;
    }
    return -1;
}

void deleteOffer(Repository *repo, int index)
{
    /*
        calls the function delete from the dynamic array to delete element to a position
        destroys the deleted offer
    */
    Offer of = deleteFromProsition(repo->offers, index);
    
    destroyOffer(&of);
}

DynamicArray *copyRepo(DynamicArray *arr)
{
    /*
        creates a new dynamic array and copies all information from given array to it

        return: the copy array
    */
    DynamicArray* da = createArray(50);
    da->capacity = arr->capacity;
    da->length = arr->length;

    // da->elems = (Offer*)malloc(arr->capacity * sizeof(Offer));

    for(int i = 0; i < arr->length; i++)
    {
        setType(&da->elems[i], getType(&arr->elems[i]));
        setDepar(&da->elems[i], getDepar(&arr->elems[i]));
        setDest(&da->elems[i], getDest(&arr->elems[i]));
        // da->elems[1].destination = malloc(sizeof(char) * (strlen(getDest(&arr->elems[i])) + 1));
        // strcpy(da->elems[i].destination, getDest(&arr->elems[i]));
        da->elems[i].price = arr->elems[i].price;
    }

    return da;
}

