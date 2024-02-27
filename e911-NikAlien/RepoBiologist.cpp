//
// Created by Carp Nicoleta on 30.06.2023.
//

#include "RepoBiologist.h"
#include "sstream"
#include "fstream"

RepoBiologist::RepoBiologist() {
    this->readFromFile();

}

void RepoBiologist::readFromFile() {
    std::vector<std::string> result;
    std::string line;
    std::ifstream fin("biologist.txt");

    while(getline(fin, line))
    {
        std::stringstream ss(line);
        std::string take;
        while(getline(ss, take, ','))
        {
            result.push_back(take);
        }
        std::vector<std::string> sp;
        for(int i = 1; i < result.size(); i++)
        {
            sp.push_back(result[i]);
        }
        Biologist b(result[0], sp);
        this->bios.push_back(b);
        result.clear();
    }
}
