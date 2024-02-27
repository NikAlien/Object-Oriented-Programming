//
// Created by Carp Nicoleta on 27.04.2023.
//

#include "Repo.h"

Repo::Repo(std::vector<Protein> vect) {
    this->proteinList = vect;
}

std::vector<Protein> Repo::getAllProtein() const {
    return this->proteinList;
}


void Repo::addProtein(Protein pr) {
    /*Input: pr - type Protein
     * it is added to the vector using the push_back funtion
     * */
    this->proteinList.push_back(pr);
}

int Repo::searchProtein(const std::string org, const std::string name) {
    for(int i = 0; i < this->proteinList.size(); i++)
    {
        if(this->proteinList[i].getOrganism() == org && this->proteinList[i].getName() == name)
            return i;
    }
    return -1;
}

void Repo::remove(int index) {
    this->proteinList.erase(this->proteinList.begin() + index);
}
