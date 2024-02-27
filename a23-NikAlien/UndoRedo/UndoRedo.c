#include "UndoRedo.h"
#include <stdlib.h>
#include <stdio.h>

UndoRedo *createUnRe(int dim, Repository* repo)
{
    /*
        Create undo redo array
        return: teh unre array
    */
    UndoRedo* unre = (UndoRedo*)malloc(sizeof(UndoRedo));

    if(unre == NULL)
        return NULL;

    unre->count = 0;
    unre->capacity = dim;
    unre->current_index = -1;
    unre->total = 0;

    unre->repos = (DynamicArray**)malloc(dim * sizeof(DynamicArray*));
    // for(int i = 0; i <= dim; i++)
    //     unre->repos[unre->current_index] = (DynamicArray*)malloc(sizeof(DynamicArray)*repo->offers->length);

    return unre;
}

void destroyUnRe(UndoRedo *unre)
{
    /* 
        destroy the unre array
    */
    if(unre == NULL)
        return;
    
    for(int index = 0; index <= unre->total; index++)
    {
        for(int j = 0; j < getLength(unre->repos[index]); j++)
            destroyOffer(&unre->repos[index]->elems[j]);

        destroy(unre->repos[index]);
    }

    free(unre->repos);
    unre->repos = NULL;
    free(unre);
}

void resizeUnRe(UndoRedo *unre)
{
    /*
        if unre length reaches max capacity, we incrase it by *2
    */
    if(unre == NULL)
        return;

    unre->capacity *= 2;
    unre->repos = (DynamicArray**)realloc(unre, unre->capacity * sizeof(DynamicArray*));
    
}

void addToUnRe(UndoRedo *unre, Repository* t)
{
    /*
        copy to unre the given repository
        chaneg the current index
    */
    if(unre == NULL)
        return;

    if(unre->repos == NULL)
        return;
    
    if(unre->capacity == unre->current_index)
        resizeUnRe(unre);
        
    unre->current_index++;
    unre->count++;
    if(unre->total < unre->current_index)
        unre->total = unre->current_index;
    unre->repos[unre->current_index] = copyRepo(t->offers);
}

int redoOp(UndoRedo *unre)
{
    /*
        if current index is invalid return
        else move forward
    */
    if(unre->current_index == unre->total)
        return 0;
    unre->current_index++;
    return 1;
}

int undoOp(UndoRedo *unre)
{
    /*
        if current index is invalid return
        else move backward
    */
    if(unre->current_index == 0)
        return 0;
    unre->current_index--;
    return 1;
}
