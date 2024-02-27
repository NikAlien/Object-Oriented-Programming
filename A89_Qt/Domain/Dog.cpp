#include "Dog.h"
#include <sstream>

std::vector<std::string> tokenize(const std::string& str, char delimiter)
{
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

Dog::Dog() : breed(""), name(""), age(0), photograph(""), clientList("false"){}

Dog::Dog(const std::string& _breed, const std::string& _name, int _age, const std::string& _photograph, const std::string& flag)
{
    /* The Dog class constructor */
    this->breed = _breed;
    this->name = _name;
    this->age = _age;
    this->photograph = _photograph;
    this->clientList = flag;
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

std::string Dog::getFlag() const {
    /* gets the dog's flag which represents if it's in the adoption list or not*/
    return this->clientList;
}

void Dog::setFlag(const std::string& flag) {
    /* sets the dog's flag to the new flag*/
    this->clientList = flag;
}

std::istream &operator>>(std::istream &is, Dog &s) {
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 5) // make sure all the song data was valid
        return is;

    s.breed = tokens[0];
    s.name = tokens[1];
    s.age = std::stoi(tokens[2]);
    s.photograph = tokens[3];
    s.clientList = tokens[4];

    return is;
}

std::ostream &operator<<(std::ostream &os, const Dog &s) {
    os << s.breed << "," << s.name << "," << s.age << "," << s.photograph << "," << s.clientList << "\n";
    return os;
}

