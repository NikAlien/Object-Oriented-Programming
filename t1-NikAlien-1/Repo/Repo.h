#pragma once
#include "Domain/Protein.h"
#include <vector>

class Repo {
private:
    std::vector<Protein> proteinList;

public:
    Repo(std::vector<Protein> vect);

    std::vector<Protein> getAllProtein() const;
    void addProtein(Protein pr);
    int searchProtein(const std::string org, const std::string name);
    void remove(int index);
};



