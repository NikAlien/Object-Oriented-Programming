#pragma once
#include "vector"
#include "Bacterium.h"


class RepoBacteria {
private:
    std::vector<Bacterium> bac;

public:
    RepoBacteria();
    ~RepoBacteria();
    void readFromFile();
    std::vector<Bacterium>& getList() {return bac;}
    void addBacteriaRepo(std::string name, std::string species, int size, std::vector<std::string> dis);
};


