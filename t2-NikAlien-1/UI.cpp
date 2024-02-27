#include "UI.h"
#include "iostream"
#include "string"

using namespace std;

UI::UI(Service *s) {
    this->serv = s;
}

void UI::printMenu() {
    cout << "Menu: " << endl;
    cout << "1. Add car" << endl;
    cout << "2. Show all cars" << endl;
    cout << "3. Exit" << endl;
    cout << "--> ";

}

void UI::start() {
    string choice;

    while(true)
    {
        this->printMenu();
        getline(cin, choice);
        if(choice == "1")
            continue;
        else if (choice == "2")
            this->printAll();
        else if(choice == "3")
            break;
        else
            continue;
    }
}

void UI::printAll() {
    std::vector<Car> rp = this->serv->getAll();

    for(auto & i : rp)
        cout << i.toStr();

}
