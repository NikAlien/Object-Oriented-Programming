#include "Domain/Offer.h"
#include "Repo/Repo.h"
#include "Service/Service.h"
#include "UndoRedo/UndoRedo.h"
#include "UI/UI.h"
#include <stdio.h>

/*
    TODO:
        Look if add new history to undo and it's in a position smaller than how many repos there were before
        if there are memo leaks
*/

int main()
{
    DynamicArray* arr = createArray(100);
    Repository* repo = createRepo(arr);

    UndoRedo* unre = createUnRe(10, repo);
    Service* serv = createService(repo, unre);

    addToRepo(serv, "seaside", "Turkey", "03/11/2024", 140.5);
    addToRepo(serv, "seaside", "Greece", "20/10/2024", 370.5);
    addToRepo(serv, "mountain", "Greece", "03/11/2023", 340.5);
    addToRepo(serv, "seaside", "Alaska", "03/07/2023", 240.5);
    addToRepo(serv, "seaside", "France", "10/05/2023", 1500.5);
    addToRepo(serv, "city break", "Albania", "31/04/2023", 200);
    addToRepo(serv, "city break", "France", "15/09/2023", 660);
    addToRepo(serv, "city break", "Ukraine", "10/05/2024", 330.5);
    addToRepo(serv, "mountain", "Egypt", "10/09/2023", 550);
    addToRepo(serv, "mountain", "Himalaya", "27/06/2023", 700);

    UI* ui = createUi(serv);

    start(ui);

    destroyUI(ui);
    return 0;
}