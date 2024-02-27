//
// Created by Carp Nicoleta on 30.06.2023.
//

#include "Service.h"
#include "sstream"

std::vector<Bacterium>& Service::getBacteria() {
    std::vector<Bacterium>& sorted = bacteria.getList();

    for(int i = 0; i < sorted.size() - 1; i++)
        for(int j = 0; j < sorted.size() - 1; j++)
            if(sorted[j].getName() > sorted[j + 1].getName())
                std::swap(sorted[j], sorted[j + 1]);
    return bacteria.getList();
}

void Service::addBacteria(std::string name, std::string species, int size, std::string dis) {

    for(auto b : bacteria.getList())
    {
        if(name == b.getName() && species == b.getSpecies())
        {
            throw std::runtime_error("This name and species already exists");
        }
    }


    std::vector<std::string> diseas;
    std::stringstream ss(dis);
    std::string take;
    while (getline(ss, take, ','))
    {
        diseas.push_back(take);
    }
    bacteria.addBacteriaRepo(name, species, size, diseas);
}
