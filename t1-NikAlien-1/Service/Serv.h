#pragma once
#include "Repo/Repo.h"
#include "Domain/Protein.h"

class Serv {
private:
    Repo* prList;

public:
    Serv(Repo* list);

    void servInit();
    std::vector<Protein> getAll() const;
    std::vector<Protein> searchPr(const std::string seq) const;
    int removePr(const std::string org, const std::string name);

};

