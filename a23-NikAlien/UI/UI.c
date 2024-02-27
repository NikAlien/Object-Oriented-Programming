#include "UI.h"
#include "../Domain/Offer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

UI *createUi(Service *serv)
{
    UI* ui = malloc(sizeof(UI));

    if(ui == NULL)
        return NULL;

    ui->serv = serv;

    return ui;
}

void destroyUI(UI *ui)
{
    if(ui == NULL)
        return;
    
    destroyService(ui->serv);
    free(ui);
}

void start(UI* ui)
{
    char choice;
    char s[30];
    addToUnRe(ui->serv->unre ,ui->serv->repo);

    while(1)
    {
        printMenu();
        printf("\n--> ");
        scanf(" %c", &choice);
        fgets(s, 30, stdin);

        if(s[0] != '\n')
            printf("--- Comment Unidentifiable ---\n");
        else
        {
            switch (choice)
            {
            case '1':
                addDetails(ui);
                break;

            case '2':
                deleteDetails(ui);
                break;
            
            case '3':
                updateDetails(ui);
                break;
            
            case '4':
                printf("\nWhat are you looking for?\n");
                printf("--> ");
                fgets(s, 30, stdin);

                if (s[0] == '\n')
                {
                    displayList(ui);
                }
                else
                {
                    displaySearch(ui, s);
                }
                break;

            case '5':
            displayFiltered(ui);
                break;

            case '6':
                undoRepo(ui);
                break;

            case '7':
                redoRepo(ui);
                break;

            case '8':
                printf("The end\n");
                return;
            
            default:
                printf("--- Comment Unidentifiable ---\n");
                break;
            }
        }
    }  
}

void printMenu()
{
    printf("\n\nMenu: \n");
    printf("   1. Add new offer\n");
    printf("   2. Delete an offer\n");
    printf("   3. Update details of an offer\n");
    printf("   4. Search tourist offers by destination\n");
    printf("   5. Display offers of chosen type\n");
    printf("   6. Undo\n");
    printf("   7. Redo\n");
    printf("   8. Exit");
}

void addDetails(UI *ui)
{
    char type[30], dest[30], date[30], s[10];
    double price;
    printf("\nNew offer will consist of: ");
    printf("\nType --> ");
    fgets(type, 30, stdin);
    type[strlen(type) - 1] = '\0';
    printf("\nDestination --> ");
    scanf(" %s", dest);
    printf("\nDeparture date --> ");
    scanf(" %s", date);
    printf("\nPrice --> ");
    scanf(" %lf", &price);
    fgets(s, 10, stdin);

    if(s[0] != '\n' || price < 0)
    { 
        printf("\n--- Give a positive float nr for price ---\n");
        return;
    }

    if(dateValid(date) == 0)
    { 
        printf("\n    --- Use format: day/month/year ---\n");
        printf("--- And make sure to write a valid date ---\n");
        return;
    }

    if(typeValid(type) == 0)
    {
        printf("\n--- Type must be: seaside, mountain or city break ---\n");
        return;
    }

    int flag = addToRepo(ui->serv, type, dest, date, price);
    if(flag == 0)
    {
            addToUnRe(ui->serv->unre ,ui->serv->repo);
            printf("\nThe offer was added\n");
    }
    else
            printf("\nOffer already in repo\n");
}

void deleteDetails(UI* ui)
{
    char dest[30], date[30];
    printf("\nWhich offer do you want to delete: ");
    printf("\nDestination --> ");
    scanf(" %s", dest);
    printf("\nDeparture date --> ");
    scanf(" %s", date);

    if(dateValid(date) == 0)
    { 
        printf("\n    --- Use format: day/month/year ---\n");
        printf("--- And make sure to write a valid date ---\n");
        return;
    }

    int flag = deleteFromRepo(ui->serv, dest, date);
    if(flag == 0)
    {
            printf("\nThe offer was deleted\n");
            addToUnRe(ui->serv->unre ,ui->serv->repo);
    }
    else
            printf("\nNo such offer in repo\n");
}

void updateDetails(UI* ui)
{
    char dest[30], date[30], type[30], s[10];
    double price;
    printf("\nWhich offer do you want to update: ");
    printf("\nDestination --> ");
    scanf(" %s", dest);
    printf("\nDeparture date --> ");
    scanf(" %s", date);

    printf("\nThe new type --> ");
    fgets(type, 30, stdin);
    fgets(type, 30, stdin);
    type[strlen(type) - 1] = '\0';
    printf("\nThe new price --> ");
    scanf(" %lf", &price);
    fgets(s, 10, stdin);

    if(s[0] != '\n' || price < 0)
    { 
        printf("\n--- Give a positive float nr for price ---\n");
        return;
    }

    if(dateValid(date) == 0)
    { 
        printf("\n    --- Use format: day/month/year ---\n");
        printf("--- And make sure to write a valid date ---\n");
        return;
    }

    if(typeValid(type) == 0)
    {
        printf("\n--- Type must be: seaside, mountain or city break ---\n");
        return;
    }

    int flag = updateOfInfo(ui->serv, type, dest, date, price);
    if(flag == 0)
    {
            printf("\nThe offer was updated\n");
            addToUnRe(ui->serv->unre ,ui->serv->repo);
    }
    else
            printf("\nNo such offer in repo\n");
}

void displaySearch(UI* ui, char* str)
{
    char st[200];
    DynamicArray* dy = listSearchDestination(ui->serv, str);


    if(getLength(dy) == 0)
        printf("\nNo offers found\n\n");
    else{
        printf("\nThe filtered list is: \n\n");
        for(int i = 0; i < getLength(dy); i++)
        {
            toString(&dy->elems[i], st);
            printf("%s", st);
        }
        destroy(dy);
    }
}

void displayFiltered(UI *ui)
{
    char type[30], date[30], str[200];
    printf("\nWhat type of offer you looking for? ");
    printf("\nType --> ");
    fgets(type, 30, stdin);
    type[strlen(type) - 1] = '\0';
    printf("\nAfter what date you looking for?");
    printf("\nDate --> ");
    scanf(" %s", date);

    if(dateValid(date) == 0)
    { 
        printf("\n    --- Use format: day/month/year ---\n");
        printf("--- And make sure to write a valid date ---\n");
        return;
    }

    DynamicArray* dy = listSearchType(ui->serv, type, date);

    if(getLength(dy) == 0)
        printf("\nNo offers found\n\n");
    else{
        printf("\nThe filtered list is : \n\n");
        for(int i = 0; i < getLength(dy); i++)
        {
            toString(&dy->elems[i], str);
            printf("%s", str);
        }
        destroy(dy);
    }

}

void displayList(UI *ui)
{
    char st[200];
    DynamicArray* dy = listDisplay(ui->serv);

    printf("\nThe current list is : \n\n");
    for(int i = 0; i < getLength(dy); i++)
    {
        toString(&dy->elems[i], st);
        printf("%s", st);
    }
    destroy(dy);
}

void undoRepo(UI* ui)
{
    if(undoOp(ui->serv->unre) == 0)
        printf("No more to undo.\n");
    else
    {
        copyRepoServ(ui->serv, ui->serv->unre);
        printf("The undo is complete\n");
    }
}

void redoRepo(UI* ui)
{
    if(redoOp(ui->serv->unre) == 0)
        printf("No more to to redo.\n");
    else
    {
        copyRepoServ(ui->serv, ui->serv->unre);
        printf("The redo is completen");
    }
}