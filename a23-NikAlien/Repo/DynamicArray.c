#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray *createArray(int capacity)
{
    /*
        Creats a dynamic array
        return: the dynamic array
    */
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));

    if(da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;

    da->elems = (TElem*)malloc(capacity * sizeof(TElem));
    if(da->elems == NULL)
        return NULL;

    return da;
}

void destroy(DynamicArray *arr)
{
    /*
        Destroys the dynamic array
    */
    if(arr == NULL)
        return;

    free(arr->elems);
    arr->elems = NULL;

    free(arr);
}

void resize(DynamicArray* arr)
{
    /*
        allocates more memory to the array in case its length approached its max capacity
    */
    if(arr == NULL)
        return;

    arr->capacity *= 2;
    TElem* aux = realloc(arr->elems, arr->capacity * sizeof(TElem));
    if(aux == NULL)
        return;
    arr->elems = aux;
}

void addToPosition(DynamicArray *arr, TElem t, int pos)
{
    /*
        Adds a TElem into a specified position in the array
    */
    if(arr == NULL)
        return;

    if(arr->elems == NULL)
        return;
        
    for(int i = arr->length; i >= pos + 1; i--)
        arr->elems[i] = arr->elems[i - 1];

    arr->elems[pos] = t;

    arr->length++;
    if (arr->length == arr->capacity)
        resize(arr);
}

TElem deleteFromProsition(DynamicArray *arr, int pos)
{
    /*
        Deletes a TElem from a specific position in the array
        return: the deleted element
    */
    TElem t = arr->elems[pos];

    arr->length--;
    for(int i = pos; i < arr->length; i++)
        arr->elems[i] = arr->elems[i + 1];
    
    return t;
}

int getLength(DynamicArray *arr)
{
    /*
        return: the dynamic array's length
    */
    if(arr == NULL)
        return 0;
    return arr->length;
}

int getCapacity(DynamicArray *arr)
{
    /*
        return: the dynamic array's max capacity
    */
    if(arr == NULL)
        return 0;
    return arr->capacity;
}
