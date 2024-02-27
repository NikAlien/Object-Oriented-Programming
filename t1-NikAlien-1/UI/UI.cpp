//
// Created by Carp Nicoleta on 27.04.2023.
//

#include <iostream>
#include "UI.h"

using namespace std;

UI::UI(Serv *serv) {
    this->service = serv;
}

void UI::start() {
    std::string choice;


    while (true){
        this->printMenu();
        getline(std::cin, choice);

        if(choice == "1")
            this->removeProtein();
        else if(choice == "2")
            this->displayAll();
        else if(choice == "3")
            this->searchProtein();
        else if (choice == "4")
            break;
        else
            cout << "No such command";
    }
}

void UI::displayAll() {
    for(const auto& pr : this->service->getAll())
    {
        cout << pr.getOrganism() << " | " << pr.getName() << " | "<< pr.getSequence() << endl;
    }
}

void UI::printMenu() {
    cout << "\n\n1. Remove protein";
    cout << "\n2. Show all";
    cout << "\n3. Search protein";
    cout << "\n4. Exit";

    cout << "\n   Choice --> ";
}

void UI::removeProtein() {
    string org, name;

    cout << "\nGive organism: ";
    getline(std::cin, org);
    cout << "\nGive name: ";
    getline(std::cin, name);

    int flag = this->service->removePr(org, name);

    if(flag)
        cout << "\nRemove with success!";
    else
        cout << "\nNo such protein!";

}

void UI::searchProtein() {
    string seq;
    cout << "\nGive sequence: ";
    getline(std::cin, seq);
    vector<Protein> fil = this->service->searchPr(seq);
    if(fil.empty())
    {
        cout << "\nNo such protein!";
    }
    else
        for(const auto& pr : fil)
        {
            cout << pr.getOrganism() << " | " << pr.getName() << " | "<< pr.getSequence() << endl;
        }

}
