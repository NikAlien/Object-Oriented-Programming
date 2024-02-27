#include "Dog.h"

Dog::Dog() : breed(""), name(""), age(0), photograph(""), clienList(false){}

Dog::Dog(const std::string &_breed, const std::string &_name, int _age, const std::string &_photograph, bool flag)
{
    /* The Dog class constructor */
    this->breed = _breed;
    this->name = _name;
    this->age = _age;
    this->photograph = _photograph;
    this->clienList = flag;
}

std::string Dog::getBreed() const
{
    /* gets and returns the dog's breed */
    return this->breed;
}

std::string Dog::getName() const {
    /* gets and returns the dog's name */
    return this->name;
}

std::string Dog::getPhotograph() const {
    /* gets and returns the dog's photograph link */
    return this->photograph;
}

int Dog::getAge() const {
    /* gets and returns the dog's age */
    return this->age;
}

void Dog::setAge(int age) {
    /* sets the dog's age to an new value */
    this->age = age;
}

void Dog::setPhoto(const std::string &photo) {
    /* sets the dog's photo link to an new value */
    this->photograph = photo;
}

bool Dog::getFlag() const {
    /* gets the dog's flag which represents if it's in the adoption list or not*/
    return this->clienList;
}

void Dog::setFlag(bool flag) {
    /* sets the dog's flag to the new flag*/
    this->clienList = flag;
}
