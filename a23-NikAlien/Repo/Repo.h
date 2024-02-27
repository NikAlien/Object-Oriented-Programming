#pragma once
#include "../Domain/Offer.h"
#include "DynamicArray.h"

typedef struct
{
    DynamicArray* offers;
} Repository;

Repository* createRepo(DynamicArray* arr);
void destroyRepo(Repository* repo);

int searchOffer(Repository* repo, char* dest, char* date);
void addOffer(Repository* repo, int index, Offer of);
void deleteOffer(Repository* repo, int index);
DynamicArray* copyRepo(DynamicArray* arr);