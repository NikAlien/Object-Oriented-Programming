#include <iostream>
#include <stdlib.h>
#include "UIUser.h"

UIUser::UIUser(Service *serv) {
    this->servUser = serv;
}

void UIUser::startUser() {
    std::string choice;

    while(true)
    {
        std::cout << "\n--- USER MODE ---\n";
        UIUser::MenuUser();
        std::cout << "Command: ";
        getline(std::cin, choice);

        if(choice == "look")
            this->lookAtDogs();

        else if(choice == "search")
            this->searchForDog();

        else if(choice == "dis")
            this->displayAdoptionList();

        else if(choice == "x")
            return;
        else
            std::cout << "\n!!! Comment Unidentifiable !!!\n";
    }
}

void UIUser::MenuUser() {
    std::cout << "\nLook at available dogs --> look" << std::endl;
    std::cout << "Search for specific dogs --> search" << std::endl;
    std::cout << "Display your current adoption list --> dis" << std::endl;
    std::cout << "Back to main menu --> x\n" << std::endl;
}


void UIUser::lookAtDogs() {
    DynamicArray<Dog*> dogList = this->servUser->createListUser("", -1);
    this->slideShow(&dogList);
}

void UIUser::searchForDog() {
    std::string breed, verify;
    int age;

    std::cout << "\nWhat breed are you looking for --> ";
    getline(std::cin, breed);
    if(breed.length() == 0)
    {
        DynamicArray<Dog*> dogList = this->servUser->createListUser("", -1);
        this->slideShow(&dogList);
    }
    else
    {
        if(!this->servUser->breedValid(breed)){
            std::cout << "\n!!! Breed not in data base !!!\n";
            return;
        }
        std::cout << "\nYounger than --> ";
        getline(std::cin, verify);
        if(!this->servUser->ageValid(verify)){
            std::cout << "\n!!! Age is invalid !!!\n";
            return;
        }
        age = std::stoi(verify);

            DynamicArray<Dog*> dogList = this->servUser->createListUser(breed, age);
            this->slideShow(&dogList);
    }
}

void UIUser::displayAdoptionList() {
    DynamicArray<Dog> list = *(this->servUser->getDogList());

    if(this->servUser->getAdopted() == 0)
        std::cout << "\nNo dogs in your adoption list\n";
    else {
        std::cout << "\nYOUR ADOPTION LIST:\n";
        for (int i = 0; i < list.getLength(); ++i)
            if(list[i].getFlag()){
                std::cout << list[i].getName() << " - " << list[i].getBreed() << ", " << list[i].getAge() << " y/o";
                std::cout << "\n     " << list[i].getPhotograph();
                std::cout << "\n";
            }
    }
}

void UIUser::slideShow(DynamicArray<Dog*> *dogList) {
    int len = dogList->getLength();
    if(len == 0) {
        std::cout << "\n!!! No dogs were found !!!\n";
        return;
    }

    int index = 0;
    std::string choice = "n";

    while(true)
    {
        Dog* d = dogList->operator[](index);
        if(choice == "n" || choice == "p")
            this->slideShowPrint(d);
        std::cout << "Command: ";
        getline(std::cin, choice);

        if(choice == "n") {
            if (index == len - 1)
                index = 0;
            else
                index++;
        }
        else if(choice == "p"){
            if (index == 0)
                index = len - 1;
            else
                index--;
        }
        else if(choice == "add")
        {
            if(d->getFlag()) {
                std::cout << "\n!!! Dog already in your adoption list !!!\n";
                continue;
            }
            d->setFlag(true);
            this->servUser->setAdopted(this->servUser->getAdopted() + 1);
            std::cout << "\nDog was added to your adoption list\n";
        }

        else if(choice == "del")
        {
            if(!d->getFlag()) {
                std::cout << "\n!!! Dog NOT in your adoption list !!!\n";
                continue;
            }
            d->setFlag(false);
            this->servUser->setAdopted(this->servUser->getAdopted() - 1);
            std::cout << "\nDog was removed from your adoption list\n";
        }
        else if(choice == "x")
            return;
        else
            std::cout << "\n!!! Comment Unidentifiable !!!\n";
    }

}

void UIUser::slideShowPrint(const Dog* d) {
    std::string op = std::string("open ").append(d->getPhotograph());
    system(op.c_str());
    std::cout << "\n\n\n----------------------------\n\n\n";

    std::cout << d->getName() << " - " << d->getBreed() << ", " << d->getAge() << " y/o";
    std::cout << "\n     " << d->getPhotograph();
    std::cout << "\n";
    std::cout << "\nNext --> n" << std::endl;
    std::cout << "Previous --> p" << std::endl;

    if(!d->getFlag())
        std::cout << "Add dog to adoption list --> add" << std::endl;
    else
        std::cout << "Remove dog from adoption list --> del" << std::endl;
    std::cout << "Back to main menu --> x\n" << std::endl;
}
