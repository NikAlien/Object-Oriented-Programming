#include "Offer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Offer createOffer(char* t, char* dest, char* dep, double p)
{
    /*
        Creates the offer
        return: the offer
    */
    Offer of;

    of.type = malloc(sizeof(char) * (strlen(t) + 1));
    if(of.type == NULL)
        return of;
    strcpy(of.type, t);

    of.destination = malloc(sizeof(char) * (strlen(dest) + 1));
    if(of.destination == NULL)
        return of;
    strcpy(of.destination, dest);

    of.daparture_date = malloc(sizeof(char) * (strlen(dep) + 1));
    if(of.daparture_date == NULL)
        return of;
    strcpy(of.daparture_date, dep);

    of.price = p;

    return of;
}

void destroyOffer(Offer* offer)
{
    /*
        Destroys the offer
    */
    if(offer == NULL)
        return;

    free(offer->type);
    free(offer->destination);
    free(offer->daparture_date);
}

char* getType(Offer* offer)
{
    /*
        return: the type of the offer
    */
    if(offer == NULL)
        return NULL;
    
    return offer->type;
}

char* getDest(Offer* offer)
{
    /*
        return: the destination of the offer
    */
    if(offer == NULL)
        return NULL;
    
    return offer->destination;
}

char* getDepar(Offer* offer)
{
    /*
        return: the departure date of the offer
    */
    if(offer == NULL)
        return NULL;
    
    return offer->daparture_date;
}

double getPrice(Offer* offer)
{
    /*
        return: the price of the offer
    */
    if(offer == NULL)
        return 0;
    
    return offer->price;
}

void setType(Offer* offer, char* type)
{
    /*
        sets the type to a new one
    */
    offer->type = realloc(offer->type, sizeof(char) * (strlen(type) + 1));
    strcpy(offer->type, type);
}

void setDest(Offer* offer, char* dest)
{
    /*
        sets the destination to a new one
    */
    offer->destination = realloc(offer->destination, sizeof(char) * (strlen(dest) + 1));
    strcpy(offer->destination, dest);
}

void setDepar(Offer* offer, char* dep)
{
    /*
        sets the departure date to a new one
    */
    offer->daparture_date = realloc(offer->daparture_date, sizeof(char) * (strlen(dep) + 1));
    strcpy(offer->daparture_date, dep);
}

void setPrice(Offer* offer, double price)
{
    /*
        sets the price to a new one
    */
    offer->price = price;
}

void toString(Offer *offer, char* str)
{
    /*
        returns: string that will be printed with the offer's information
    */
    sprintf(str, "%s -> %s  |  %s  |  %.2f$\n", offer->type, offer->destination, offer->daparture_date, offer->price);
}
