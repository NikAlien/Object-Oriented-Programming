#include <vector>
#include "Service.h"
#include "RepoException.h"

Service::Service(FileAdoptList* list, const DogValidator& v) {
    this->dog_list = list;
    this->validator = v;
    this->dogsAdopted = 0;
}

void Service::addDogToList(const std::string& breed, const std::string& name, const std::string& age, const std::string& photo) {
    int verification = this->dog_list->searchDog(name);
    this->validator.validate(breed, age);

    if(verification == -1) {
        Dog d(breed, name, std::stoi(age), photo, "false");
        this->dog_list->addDog(d);
        return;
    }
    else
        throw RepoException("\nThere is already another dog with this name\n");
}

void Service::removeDogFromList(const std::string &name) {
    int index = this->dog_list->searchDog(name);
    if(index == -1)
        throw RepoException("\nThere is no dog with this name\n");
    this->dog_list->removeDog(index);
}

void Service::updateDogAge(const std::string &name, const std::string& age) {
    int index = this->dog_list->searchDog(name);
    if(index == -1)
        throw RepoException("\nThere is no dog with this name\n");
    this->validator.validate("husky", age);
    this->dog_list->updateDog(index, std::stoi(age), "");
}

void Service::updateDogPhoto(const std::string &name, const std::string &photo) {
    int index = this->dog_list->searchDog(name);
    if(index == -1)
        throw RepoException("\nThere is no dog with this name\n");
    this->dog_list->updateDog(index, -1, photo);
}

std::vector<Dog> *Service::getDogList() const {
    return this->dog_list->getDogs();
}

void Service::makeNameValid(std::string &name) {
    for (auto & i : name) {
        if(i < 97)
            i += 32;
    }
    if(name[0] >90 )
        name[0] -= 32;
}

void Service::makeLinkValid(std::string &link) {
    if(link.find("https://") == std::string::npos)
        link.insert(0, "https://");
}

std::vector<Dog> Service::createListUser(const std::string& filter, const std::string& age) {
    std::vector<Dog> filteredList;
    std::vector<Dog> list = *(this->getDogList());

    if(filter.empty() && age == "-1")
    {
        for(auto &d : list)
        {
            filteredList.push_back(d);
        }
    } else
    {
        this->validator.validate(filter, age);
        int a = std::stoi(age);
        for(auto &d: list)
            if(d.getBreed() == filter && d.getAge() <= a)
                filteredList.push_back(d);
    }
    return filteredList;
}

int Service::getAdopted() const {
    return this->dogsAdopted;
}

void Service::setAdopted(const std::string &name) {
    int index = this->dog_list->searchDog(name);
    std::vector<Dog> list = *(this->getDogList());
    if(list[index].getFlag() == "false")
        this->dog_list->updateDogFlag(index, "true");
    else
        this->dog_list->updateDogFlag(index, "false");
}

void Service::openAdoptList() const {
    this->saveAdoptList();
    this->dog_list->displayList();
}

void Service::saveAdoptList() const {
    if(this->dog_list == nullptr)
        return;

    this->dog_list->writeToFile();
}

