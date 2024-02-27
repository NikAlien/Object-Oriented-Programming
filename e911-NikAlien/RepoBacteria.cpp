//
// Created by Carp Nicoleta on 30.06.2023.
//

#include "RepoBacteria.h"
#include "sstream"
#include "fstream"

RepoBacteria::RepoBacteria() {
    this->readFromFile();
}

void RepoBacteria::readFromFile() {
    std::vector<std::string> result;
    std::string line;
    std::ifstream fin("bacteria.txt");

    while(getline(fin, line))
    {
        std::stringstream ss(line);
        std::string take;
        while(getline(ss, take, ','))
        {
            result.push_back(take);
        }
        std::vector<std::string> sp;
        for(int i = 3; i < result.size(); i++)
        {
            sp.push_back(result[i]);
        }
        Bacterium b(result[0], result[1], std::stoi(result[2]), sp);
        this->bac.push_back(b);
        result.clear();
    }
}

void RepoBacteria::addBacteriaRepo(std::string name, std::string species, int size, std::vector<std::string> dis) {

    Bacterium b(name, species, size, dis);
    this->bac.push_back(b);
}

RepoBacteria::~RepoBacteria() {

    std::ofstream fout("/Users/carpnicoleta/Documents/UniFiles/Semester2/OOP/FinalExam/bacteria.txt");

    for(auto b : this->bac)
    {
        fout << b.toString();
    }

}
