#include "Repo.h"
#include "vector"

Repository::Repository(std::vector<Dog> *arr) {
    this->dogs = arr;
}

void Repository::addDog(const Dog d) {
    dogs->push_back(d);
}

std::vector<Dog> *Repository::getDogs() const{
    return this->dogs;
}

void Repository::removeDog(int index) {
    this->dogs->erase(dogs->begin() + index);
}

void Repository::updateDog(int index, int age, const std::string& photo) {
    Dog d = this->dogs->operator[](index);
    if(age < 0)
        d.setPhoto(photo);
    else
        d.setAge(age);
    this->dogs->at(index) = d;
}

int Repository::searchDog(const std::string &name) {
    int index = 0;
    while(index < this->dogs->size())
    {
        if(name == this->dogs->operator[](index).getName())
            return index;
        index++;
    }
    return -1;
}
