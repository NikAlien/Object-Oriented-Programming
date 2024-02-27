#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include "Repository/RepoException.h"
#include "GUI/WelcomeGUI.h"


using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
//    QStackedWidget* app = new QStackedWidget();


//    FileAdoptList* point = new HTMLAdoptList("AdoptionList.html", "Dogs.txt");
//    DogValidator v;
//    Service serv(point, v);
//    QWidget* gui = new AdminGUI();

//    FileAdoptList* point = new HTMLAdoptList("AdoptionList.html", "Dogs.txt");
//    DogValidator v;
//    Service serv(point, v);
//    std::vector<Dog*> dogList = serv.createListUser("", "-1");
//    QWidget* gui = new SlideShow(dogList[0]);
    QWidget* gui = new WelcomeGUI();
//    AdminGUI* gui = new AdminGUI(point);
//            app->addWidget(wel);
//    app->setCurrentIndex(0);
//    wel->show();
//    app->widget(0)->show();
//    auto g = app->widget(0);
//    g->show();
    gui->show();

//    try {
//        FileAdoptList* point = nullptr;
//        while (true) {
//            cout << "What type of file would you like to use to store the playlist (CSV/HTML)?\n --> ";
//            string fileType;
//            getline(std::cin, fileType);
//            if (fileType == "html") {
//                point = new HTMLAdoptList("AdoptionList.html", "Dogs.txt");
//                break;
//            }
//            else if (fileType == "csv") {
//                point = new CSVAdoptList("AdoptionList.csv", "Dogs.txt");
//                break;
//            }
//            else
//                cout << "\n--- No such type ---\n";
//        }
//        DogValidator v;
//        Service serv(point, v);
//        UI ad(&serv);
//        ad.start();
//    }
//    catch(FileException& e) {
//        cout << e.getErrors();
//    }
    return a.exec();
}
