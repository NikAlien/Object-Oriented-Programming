#include "Domain/Offer.h"
#include "Repo/Repo.h"
#include "Repo/DynamicArray.h"
#include "Service/Service.h"
#include "UndoRedo/UndoRedo.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void testDomain()
{
    Offer of = createOffer("seaside", "Greece", "03/11/2023", 340.5);
    assert(strcmp(getDepar(&of), "03/11/2023") == 0);
    assert(strcmp(getDest(&of), "Greece") == 0);
    assert(strcmp(getType(&of), "seaside") == 0);
    assert(getPrice(&of) == 340.5);
    
    // Offer of1 = createOffer("seaside", "Greece", "03/11/2023", 340.5);
    // Offer of2 = createOffer("mountain", "Alaska", "03/11/2023", 340.5);
    // Offer of3 = createOffer("mountain", "LA", "03/11/2023", 340.5);
    // printf("%s\n", getType(&of));
    // printf("%s\n", getDest(&of));
    // printf("%s\n", getDepar(&of));
    // printf("%.2f\n", getPrice(&of));

    // printf("\nChange destination\n");
    setDest(&of, "Turkey");
    // printf("%s\n", getDest(&of));

    // printf("\nChange Type\n");
    setType(&of, "Mountain");
    // printf("%s\n", getType(&of));

    // printf("\nChange date\n");
    setDepar(&of, "05/12/2023");
    // printf("%s\n", getDepar(&of));

    // printf("\nChange price\n");
    setPrice(&of, 568.8);
    // printf("%.2f\n", getPrice(&of));

    // char st[200];
    // toString(&of, st);
    // printf("%s", st);

    // Repository* repo = createRepo();
    // addOffer(repo, 0, of);
    // addOffer(repo, 1, of1);
    // addOffer(repo, 2, of2);
    // printf("Length - %d | Capacity - %d\n", getSize(repo), getCapacity(repo));

    // deleteOffer(repo, 1);
    // toString(&repo->offers[1], st);
    // printf("\n%s", st);
    // // upOffer(repo, 1, of3);
    // toString(&repo->offers[1], st);
    // printf("\n%s", st);
    // printf("\nLength - %d | Capacity - %d\n", getSize(repo), getCapacity(repo));

    // destroyRepo(repo);

    assert(strcmp(getDepar(&of), "05/12/2023") == 0);
    assert(strcmp(getDest(&of), "Turkey") == 0);
    assert(strcmp(getType(&of), "Mountain") == 0);
    assert(getPrice(&of) == 568.8);

    destroyOffer(&of);
}

void testDynamicArray()
{
    DynamicArray* arr = createArray(1);
    Offer of = createOffer("seaside", "Greece", "03/11/2023", 340.5);
    assert(getCapacity(arr) == 1);

    addToPosition(arr, of, 0);
    assert(getCapacity(arr) == 2);
    assert(getLength(arr) == 1);

    deleteFromProsition(arr, 0);
    assert(getCapacity(arr) == 2);
    assert(getLength(arr) == 0);
    destroyOffer(&of);
    destroy(arr);
}

void testRepo()
{   
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);

    Offer of3 = createOffer("seaside", "Turkey", "03/11/2023", 340.5);
    Offer of2 = createOffer("moutain", "Greece", "03/11/2023", 300.5);
    Offer of1 = createOffer("city break", "Albania", "31/04/2023", 200);

    addOffer(repo, 0, of1);
    addOffer(repo, 1, of3);
    addOffer(repo, 1, of2);

    assert(getLength(repo->offers) == 3);
    assert(repo->offers->elems[0].price < repo->offers->elems[1].price);
    assert(repo->offers->elems[1].price < repo->offers->elems[2].price);

    deleteOffer(repo, 1);
    assert(getLength(repo->offers) == 2);
    assert(repo->offers->elems[1].price == 340.5);

    destroyRepo(repo);
}

void testCopyRepo()
{
    /*
        it creates an additional copy somewhere
    */
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);

    Offer of1 = createOffer("seaside", "Turkey", "03/11/2023", 340.5);

    addOffer(repo, 0, of1);

    DynamicArray* copy = copyRepo(repo->offers);

    assert(getLength(repo->offers) == getLength(copy));
    assert(strcmp(repo->offers->elems[0].destination, copy->elems[0].destination) == 0);
    assert(strcmp(repo->offers->elems[0].daparture_date, copy->elems[0].daparture_date) == 0);

    // destroyOffer(&copy->elems[0]);
    // destroy(copy);
    // destroyRepo(repo);
}

void testServiceAdd()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    Offer of1 = createOffer("seaside", "Turkey", "03/11/2023", 340.5);

    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "moutain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);
    addToRepo(serv, "seaside", "France", "10/05/2023", 1500.5);
    addToRepo(serv, "city break", "Albania", "31/04/2023", 200);
    addToRepo(serv, "city break", "France", "15/09/2023", 660);

    assert(serv->repo->offers->length == 7);
    assert(strcmp(getDepar(&serv->repo->offers->elems[0]), "03/11/2024") == 0);
    assert(strcmp(getDest(&serv->repo->offers->elems[0]), "Turkey") == 0);
    assert(strcmp(getType(&serv->repo->offers->elems[0]), "seaside") == 0);
    assert(addToRepo(serv, "city break", "France", "15/09/2023", 660) == -1);
}

void testServiceDelete()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    Offer of1 = createOffer("seaside", "Turkey", "03/11/2023", 340.5);

    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "moutain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);

    assert(serv->repo->offers->length == 4);
    deleteFromRepo(serv, "Greece", "03/11/2023");

    assert(serv->repo->offers->length == 3);
    assert(strcmp(getDepar(&serv->repo->offers->elems[2]), "20/10/2024") == 0);
    assert(strcmp(getDest(&serv->repo->offers->elems[2]), "Greece") == 0);
    assert(strcmp(getType(&serv->repo->offers->elems[2]), "seaside") == 0);
    assert(deleteFromRepo(serv, "Greece", "03/11/2023") == -1);

}

void testServiceUpdate()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    Offer of1 = createOffer("seaside", "Turkey", "03/11/2023", 340.5);

    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    updateOfInfo(serv, "mountain", "Alaska", "03/07/2023", 100);

    assert(strcmp(getDepar(&serv->repo->offers->elems[0]), "03/07/2023") == 0);
    assert(strcmp(getDest(&serv->repo->offers->elems[0]), "Alaska") == 0);
    assert(strcmp(getType(&serv->repo->offers->elems[0]), "mountain") == 0);
    assert(serv->repo->offers->elems[0].price == 100 );
    assert(updateOfInfo(serv, "e","Greece", "03/11/2023", 90) == -1);
}

void testDisplay()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "moutain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);

    DynamicArray* da = listDisplay(serv);

    assert(getLength(da) == getLength(serv->repo->offers));
    assert(strcmp(getDepar(&da->elems[0]), "03/11/2024") == 0);
    assert(strcmp(getDest(&da->elems[0]), "Turkey") == 0);
    assert(strcmp(getDepar(&da->elems[3]), "20/10/2024") == 0);
    assert(strcmp(getDest(&da->elems[3]), "Greece") == 0);
}

void testSearchDest()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "moutain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);

    DynamicArray* da = listSearchDestination(serv, "ce");

    assert(getLength(da) == 2);
    assert(strcmp(getDepar(&da->elems[0]), "03/11/2023") == 0);
    assert(strcmp(getDest(&da->elems[0]), "Greece") == 0);
    assert(strcmp(getDepar(&da->elems[1]), "20/10/2024") == 0);
    assert(strcmp(getDest(&da->elems[1]), "Greece") == 0);
}

void testSearchType()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "moutain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);

    DynamicArray* da = listSearchType(serv, "seaside", "01/01/2024");

    assert(getLength(da) == 2);
    assert(strcmp(getDepar(&da->elems[0]), "03/11/2024") == 0);
    assert(strcmp(getDest(&da->elems[0]), "Turkey") == 0);
    assert(strcmp(getDepar(&da->elems[1]), "20/10/2024") == 0);
    assert(strcmp(getDest(&da->elems[1]), "Greece") == 0);

    DynamicArray* dy = listSearchType(serv, "seaside", "01/01/2025");
    assert(getLength(dy) == 0);
}

void testValidDate()
{
    assert(dateValid("32") == 0);
    assert(dateValid("rt/54/2331") == 0);
    assert(dateValid("rt/3r/3ddd") == 0);
    assert(dateValid("00/12/2023") == 0);
    assert(dateValid("10/13/2023") == 0);
    assert(dateValid("07/12/2000") == 0);
    assert(dateValid("10/10/2023") == 1);
}

void testValidType()
{
    assert(typeValid("32") == 0);
    assert(typeValid("rt/54/2331") == 0);
    assert(typeValid("seaside") == 1);
    assert(typeValid("city break") == 1);
    assert(typeValid("mountain") == 1);
}

void testUndoRedo()
{
    DynamicArray* arr = createArray(1);
    Repository* repo = createRepo(arr);
    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "moutain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);

    addToUnRe(serv->unre, serv->repo);
    assert(serv->unre->count == 1);
    assert(redoOp(serv->unre) == 0);
    addToUnRe(serv->unre, serv->repo);
    assert(undoOp(serv->unre) == 1);

}

// int main()
// {
//     testDomain();
//     testDynamicArray();
//     testRepo();
//     testCopyRepo();
//     testServiceAdd();
//     testServiceDelete();
//     testServiceUpdate();
//     testDisplay();
//     testSearchDest();
//     testSearchType();
//     testValidDate();
//     testValidType();
//     testUndoRedo();
// }