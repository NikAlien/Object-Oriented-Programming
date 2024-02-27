#include "Domain/Protein.h"
#include "Service/Serv.h"
#include "Repo/Repo.h"
#include "UI/UI.h"
#include "vector"

int main()
{
    std::vector<Protein> arr;
    Repo r(arr);
    Serv s(&r);
    s.servInit();
    UI ui(&s);

    ui.start();

}
