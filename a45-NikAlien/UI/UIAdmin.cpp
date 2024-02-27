#include <iostream>
#include "UIAdmin.h"


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
    std::string breed, name, photo, verify;
    int age, flag;

    std::cout << "\nNew dog information: ";
    std::cout << "\nName --> ";
    getline(std::cin, name);
    this->servAdmin->makeNameValid(name);

    std::cout << "\nBreed --> ";
    getline(std::cin, breed);
    if(!this->servAdmin->breedValid(breed)){
        std::cout << "\n!!! Breed not in data base !!!\n";
        return;
    }
    std::cout << "\nAge --> ";
    getline(std::cin, verify);
    if(!this->servAdmin->ageValid(verify)){
        std::cout << "\n!!! Age is invalid !!!\n";
        return;
    }
    age = std::stoi(verify);
    std::cout << "\nPhoto --> ";
    getline(std::cin, photo);
    this->servAdmin->makeLinkValid(photo);

    if(this->servAdmin->addDogToList(breed, name, age, photo) == 1)
        std::cout << "\nAdd was successful\n";
    else
        std::cout << "\nThere is already another dog with this name\n";

}

void UIAdmin::deleteDogRecord() {
    std::string name;
    std::cout << "\nWhat dog was adopted: ";
    getline(std::cin, name);
    this->servAdmin->makeNameValid(name);

    if(this->servAdmin->removeDogFromList(name) == 1)
        std::cout << "\nAdoption successful\n";
    else
        std::cout << "\nThere is no dog with this name\n";

}

void UIAdmin::updateDogRecord() {
    std::string name, photo, choice, verify;
    int age, flag = 0;

    std::cout << "\nWhat dog's info to update: ";
    getline(std::cin, name);
    this->servAdmin->makeNameValid(name);
    std::cout << "\nAge or photo: ";
    getline(std::cin, choice);

    if(choice == "age"){
        std::cout << "\nAge --> ";
        getline(std::cin, verify);
        if(!this->servAdmin->ageValid(verify)){
            std::cout << "\n!!! Age is invalid !!!\n";
            return;
        }
        age = std::stoi(verify);
        flag = this->servAdmin->updateDogAge(name, age);
    }
    else if(choice == "photo"){
        std::cout << "\nPhoto --> ";
        getline(std::cin, photo);
        this->servAdmin->makeLinkValid(photo);
        flag = this->servAdmin->updateDogPhoto(name, photo);
    }
    else {
        std::cout << "\n!!! Comment Unidentifiable !!!\n";
        return;
    }

    if(flag == 1)
        std::cout << "\nUpdate successful\n";
    else
        std::cout << "\nThere is no dog with this name\n";
}

void UIAdmin::displayDogRecord() {
    DynamicArray<Dog> list = *(this->servAdmin->getDogList());

    if(list.getLength() == 0)
        std::cout << "\nNo dogs in the data base\n";
    else {
        std::cout << "\nTHE DOGS:\n";
        for (int i = 0; i < list.getLength(); ++i) {
            std::cout << list[i].getName() << " - " << list[i].getBreed() << ", " << list[i].getAge() << " y/o";
            std::cout << "\n     " << list[i].getPhotograph();
            std::cout << "\n";
        }
    }
}
