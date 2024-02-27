#include "Domain/Dog.h"
#include "Repository/DynamicArray.h"
#include "Repository/Repo.h"
#include "Service/Service.h"
#include "UI/UIMain.h"
#include "Tests/test.h"

int main()
{
    {
        testAll();

        DynamicArray<Dog> arr(1);
        Repository repo (&arr);
        Service serv(&repo);
        serv.init();

        UI ui(&serv);
        ui.start();

    }

    return 0;
}