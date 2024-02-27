#pragma once
#include "../Repo/Repo.h"

typedef struct
{
    DynamicArray** repos;
    int count;
    int capacity;
    int current_index;
    int total;

} UndoRedo;

UndoRedo* createUnRe(int dim, Repository* repo);
void destroyUnRe(UndoRedo* unre);
void resizeUnRe(UndoRedo* unre);
void addToUnRe(UndoRedo* unre, Repository* t);

int redoOp(UndoRedo* unre);
int undoOp(UndoRedo* unre);
