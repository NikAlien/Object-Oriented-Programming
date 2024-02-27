#include "Repository/Repo.h"
#include "Service/Service.h"
#include "UI/UIMain.h"
#include "FileAdoptList.h"
#include "CSVAdoptList.h"
#include "HTMLAdoptList.h"
#include "RepoException.h"

using namespace std;

// TODO: move repo and file exceptions in repo.cpp, service is okay to not access it

int main()
{
    try {
        FileAdoptList* point = nullptr;
        while (true) {
            cout << "What type of file would you like to use to store the playlist (CSV/HTML)?\n --> ";
            string fileType;
            getline(std::cin, fileType);
            if (fileType == "html") {
                point = new HTMLAdoptList("AdoptionList.html", "Dogs.txt");
                break;
            }
            else if (fileType == "csv") {
                point = new CSVAdoptList("AdoptionList.csv", "Dogs.txt");
                break;
            }
            else
                cout << "\n--- No such type ---\n";
        }
        DogValidator v;
        Service serv(point, v);
        UI ui(&serv);
        ui.start();
    }
    catch(FileException& e)
    {
        cout << e.getErrors();
    }


    return 0;
}