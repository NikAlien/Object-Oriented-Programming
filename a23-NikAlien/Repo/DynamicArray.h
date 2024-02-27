#pragma once
#include "../Domain/Offer.h"

typedef Offer TElem;

typedef struct
{
    TElem* elems;
    int length;
    int capacity;
} DynamicArray;

DynamicArray* createArray(int capacity);
void destroy(DynamicArray* arr);
void resize(DynamicArray* arr);
void addToPosition(DynamicArray* arr, TElem t, int pos);
TElem deleteFromProsition(DynamicArray* arr, int pos);

int getLength(DynamicArray* arr);
int getCapacity(DynamicArray* arr);
