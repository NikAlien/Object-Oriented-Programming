//
// Created by Carp Nicoleta on 27.04.2023.
//

#include "Serv.h"

Serv::Serv(Repo* list) {
    this->prList = list;
}

void Serv::servInit() {
    this->prList->addProtein(Protein("Human", "Myosin-2", "MSSDSELAVFGEAA"));
    this->prList->addProtein(Protein("Human", "Keratin", "TCGSGHGFDSFGJKLKLFG"));
    this->prList->addProtein(Protein("Mouse", "Keratin", "KJGJDUWEEEEAAAMDB"));
    this->prList->addProtein(Protein("E-Coli", "tufA", "BGHDSGUIKEDCH"));
    this->prList->addProtein(Protein("E-Coli", "cspE", "JGGFRDHYTRREENV"));

}

std::vector<Protein> Serv::getAll() const {
    return this->prList->getAllProtein();
}

int Serv::removePr(const std::string org, const std::string name) {
    int index = this->prList->searchProtein(org, name);
    if(index == -1)
        return 0;
    else
    {
        this->prList->remove(index);
        return 1;
    }
}

std::vector<Protein> Serv::searchPr(const std::string seq) const {
    /* Input: seq - string that is the sequence given by the user
     * Output: filter - a vector that is created with the given sequence
     *
     * we search to see if the protein sequence has seq and than we add it to filter
     * */
    std::vector<Protein> filter;
    for(auto pr : this->prList->getAllProtein())
    {
        if(pr.getSequence().find(seq) != std::string::npos)
            filter.push_back(pr);
    }

    return filter;
}


