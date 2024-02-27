#pragma once
#include "string"
#include "vector"

class Bacterium {

private:
    std::string name;
    std::string species;
    int size;
    std::vector<std::string> diseases;

public:
    Bacterium(std::string n, std::string sp, int s, std::vector<std::string> d) : name(n), species(sp), size(s), diseases(d) {};
    std::string toString();

    std::string getName() {return this->name;}
    std::string getSpecies() {return this->species;}
    int getSize() {return this->size;}
    void setName(std::string n) {name = n;}
    void setSpecies(std::string s) {species = s;}
    void setSize(int s) {size = s;}
    std::string getDiseases();
};

