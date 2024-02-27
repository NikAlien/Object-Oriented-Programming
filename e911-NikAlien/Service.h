#pragma once
#include "vector"
#include "RepoBacteria.h"
#include "RepoBiologist.h"

class Service {

private:
    RepoBacteria& bacteria;
    RepoBiologist& biologist;

public:
    Service(RepoBacteria& bac, RepoBiologist& bio) : bacteria(bac), biologist(bio) {};
    void addBacteria(std::string name, std::string species, int size, std::string dis);
    std::vector<Bacterium>& getBacteria();

};

