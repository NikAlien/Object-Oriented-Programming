#pragma once

typedef struct
{
    char* type;
    char* destination;
    char* daparture_date;
    double price;
} Offer;

Offer createOffer(char* t, char* dest, char* dep, double p);
void destroyOffer(Offer* offer);

char* getType(Offer* offer);
char* getDest(Offer* offer);
char* getDepar(Offer* offer);
double getPrice(Offer* offer);

void setType(Offer* offer, char* type);
void setDest(Offer* offer, char* dest);
void setDepar(Offer* offer, char* dep);
void setPrice(Offer* offer, double price);

void toString(Offer* offer, char* str);