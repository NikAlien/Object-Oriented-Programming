//
// Created by Carp Nicoleta on 29.03.2023.
//

#include <iostream>
#include "UIMain.h"
#include "UIAdmin.h"
#include "UIUser.h"

UI::UI(Service *serv) {
    this->serv = serv;
}

void UI::start() {
    std::string choice;
    std::cout << "\n--- KEEP CALM AND ADOPT A PET ---\n";

    while(true)
    {
        UI::Menu();
        std::cout << "Command: ";
        getline(std::cin, choice);

        if(choice == "a")
            this->AdminMonde();

        else if(choice == "u")
            this->UserMode();

        else if(choice == "x")
        {
            std::cout << "\n\n--- END PROGRAM ---";
            return;
        }
        else
            std::cout << "\n--- Comment Unidentifiable ---\n";
    }
}

void UI::AdminMonde() {
    UIAdmin admin(this->serv);
    admin.startAdmin();
}

void UI::UserMode() {
    UIUser admin(this->serv);
    admin.startUser();
}

void UI::Menu() {
    std::cout << "\nAdmin mode --> a" << std::endl;
    std::cout << "User mode --> u" << std::endl;
    std::cout << "Exit --> x\n" << std::endl;
}
