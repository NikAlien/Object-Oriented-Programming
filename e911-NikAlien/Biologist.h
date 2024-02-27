#pragma once
#include "string"
#include "vector"

class Biologist {

private:
    std::string name;
    std::vector<std::string> species;

public:
    Biologist(std::string n, std::vector<std::string> sp) : name(n), species(sp) {};
    std::string toString();

    std::string getName() {return this->name;}
    std::vector<std::string> getSpecies() {return this->species;}

};
