#include <iostream>
#include <vector>
#include "UIAdmin.h"
#include "RepoException.h"


UIAdmin::UIAdmin(Service *servAdmin) {
    this->servAdmin = servAdmin;
}

void UIAdmin::startAdmin() {
    std::string choice;

    while(true)
    {
        std::cout << "\n--- ADMIN MODE ---\n";
        UIAdmin::MenuAdmin();
        std::cout << "Command: ";
        getline(std::cin, choice);

        if(choice == "add")
            this->addDogRecord();

        else if(choice == "del")
            this->deleteDogRecord();

        else if(choice == "up")
            this->updateDogRecord();

        else if(choice == "dis")
            this->displayDogRecord();

        else if(choice == "x")
            return;
        else
            std::cout << "\n!!! Comment Unidentifiable !!!\n";
    }
}

void UIAdmin::MenuAdmin() {
    std::cout << "\nAdd to record a new dog --> add" << std::endl;
    std::cout << "Remove from record a dog --> del" << std::endl;
    std::cout << "Update a dog's information --> up" << std::endl;
    std::cout << "Display dog records --> dis" << std::endl;
    std::cout << "Back to main menu --> x\n" << std::endl;
}

void UIAdmin::addDogRecord() {
    std::string breed, name, photo, age;

    std::cout << "\nNew dog information: ";
    std::cout << "\nName --> ";
    getline(std::cin, name);
    Service::makeNameValid(name);
    std::cout << "\nBreed --> ";
    getline(std::cin, breed);
    std::cout << "\nAge --> ";
    getline(std::cin, age);
    std::cout << "\nPhoto --> ";
    getline(std::cin, photo);
    Service::makeLinkValid(photo);

    try {
        this->servAdmin->addDogToList(breed, name, age, photo);
        std::cout << "\nAdd was successful\n";
    }
    catch (DogException& e)
    {
        for (auto error : e.getErrors())
            std::cout << error;
    }
    catch (FileException& e)
    {
        std::cout << e.getErrors();
    }
    catch (RepoException& e)
    {
        std::cout << e.getErrors();
    }

}

void UIAdmin::deleteDogRecord() {
    std::string name;
    std::cout << "\nWhat dog was adopted: ";
    getline(std::cin, name);
    Service::makeNameValid(name);

    try {
        this->servAdmin->removeDogFromList(name);
        std::cout << "\nAdoption successful\n";
    }
    catch (FileException& e)
    {
        std::cout << e.getErrors();
    }
    catch (RepoException& e)
    {
        std::cout << e.getErrors();
    }

}

void UIAdmin::updateDogRecord() {
    std::string name, photo, choice, age;

    std::cout << "\nWhat dog's info to update: ";
    getline(std::cin, name);
    Service::makeNameValid(name);
    std::cout << "\nAge or photo: ";
    getline(std::cin, choice);

    try {
        if (choice == "age") {
            std::cout << "\nAge --> ";
            getline(std::cin, age);
            this->servAdmin->updateDogAge(name, age);
        }
        else if (choice == "photo") {
            std::cout << "\nPhoto --> ";
            getline(std::cin, photo);
            Service::makeLinkValid(photo);
            this->servAdmin->updateDogPhoto(name, photo);
        }
        else {
            std::cout << "\n!!! Comment Unidentifiable !!!\n";
            return;
        }
        std::cout << "\nUpdate successful\n";
    }
    catch (DogException &e) {
        for (auto error: e.getErrors())
            std::cout << error;
    }
    catch (RepoException& e)
    {
        std::cout << e.getErrors();
    }
    catch (FileException& e)
    {
        std::cout << e.getErrors();
    }
}

void UIAdmin::displayDogRecord() {
    std::vector<Dog> list = *(this->servAdmin->getDogList());

    if(list.empty())
        std::cout << "\nNo dogs in the data base\n";
    else {
        std::cout << "\nTHE DOGS:\n";
        for (const auto & d : list) {
            std::cout << d.getName() << " - " << d.getBreed() << ", " << d.getAge() << " y/o";
            std::cout << "\n     " << d.getPhotograph();
            std::cout << "\n";
        }
    }
}
