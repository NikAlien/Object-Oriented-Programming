#include <iostream>
#include <stdlib.h>
#include <vector>
#include "UIUser.h"
#include "RepoException.h"

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

        else if(choice == "file")
            this->displayFile();

        else if(choice == "save")
            this->saveListFile();

        else if(choice == "x")
            return;
        else
            std::cout << "\n!!! Comment Unidentifiable !!!\n";
    }
}

void UIUser::MenuUser() {
    std::cout << "\nLook at available dogs --> look" << std::endl;
    std::cout << "Search for specific dogs --> search" << std::endl;
    std::cout << "Save the adoption list in a file --> save" << std::endl;
    std::cout << "Display your current adoption list --> dis" << std::endl;
    std::cout << "Look at adoption list in a file --> file" << std::endl;
    std::cout << "Back to main menu --> x\n" << std::endl;
}


void UIUser::lookAtDogs() {
    std::vector<Dog*> dogList = this->servUser->createListUser("", "-1");
    this->slideShow(&dogList);
}

void UIUser::searchForDog() {
    std::string breed, age;

    std::cout << "\nWhat breed are you looking for --> ";
    getline(std::cin, breed);
    if(breed.length() == 0)
    {
        std::vector<Dog*> dogList = this->servUser->createListUser("", "-1");
        this->slideShow(&dogList);
    }
    else
    {
        std::cout << "\nYounger than --> ";
        getline(std::cin, age);
        try {
            std::vector<Dog *> dogList = this->servUser->createListUser(breed, age);
            this->slideShow(&dogList);
        }
        catch (DogException& e)
        {
            for (auto error : e.getErrors())
                std::cout << error;
        }
    }
}

void UIUser::displayAdoptionList() {
    std::vector<Dog> list = *(this->servUser->getDogList());

    if(this->servUser->getAdopted() == 0)
        std::cout << "\nNo dogs in your adoption list\n";
    else {
        std::cout << "\nYOUR ADOPTION LIST:\n";
        for (const auto & i : list)
            if(i.getFlag()){
                std::cout << i.getName() << " - " << i.getBreed() << ", " << i.getAge() << " y/o";
                std::cout << "\n     " << i.getPhotograph();
                std::cout << "\n";
            }
    }
}

void UIUser::slideShow(std::vector<Dog*> *dogList) {
    int len = dogList->size();
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
            UIUser::slideShowPrint(d);
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
        else if(choice == "add" || choice == "del")
        {
            try {
                servUser->setAdopted(choice, d);
                std::cout << "\n Adoption list was modified \n";
            }
            catch(RepoException& e)
            {
                std::cout << e.getErrors();
                continue;
            }
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

void UIUser::displayFile() {
    try {
        this->servUser->openAdoptList();
    }
    catch(FileException& e)
    {
        std::cout << e.getErrors();
    }
}

void UIUser::saveListFile() {
    try {
        this->servUser->saveAdoptList();
    }
    catch(FileException& e)
    {
        std::cout << e.getErrors();
    }
}
