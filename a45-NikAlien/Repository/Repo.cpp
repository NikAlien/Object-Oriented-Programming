#include "Repo.h"

Repository::Repository(DynamicArray<Dog> *arr) {
    this->dogs = arr;
}

void Repository::addDog(const Dog d) {
    this->dogs->add(d);
}

DynamicArray<Dog> *Repository::getDogs() const{
    return this->dogs;
}

void Repository::removeDog(int index) {
    this->dogs->remove(index);
}

void Repository::updateDog(int index, int age, const std::string& photo) {
    Dog d = this->dogs->operator[](index);
    if(age < 0)
        d.setPhoto(photo);
    else
        d.setAge(age);
    this->dogs->update(d, index);
}

int Repository::searchDog(const std::string &name) {
    int index = 0;
    while(index < this->dogs->getLength())
    {
        if(name == this->dogs->operator[](index).getName())
            return index;
        index++;
    }
    return -1;
}
