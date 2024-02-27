//
// Created by Carp Nicoleta on 27.04.2023.
//

#include "Protein.h"

Protein::Protein() {
    this->name = "";
    this->organism = "";
    this->sequence = "";
}

Protein::Protein(const std::string org, const std::string name, const std::string seq) {
    this->name = name;
    this->organism = org;
    this->sequence = seq;
}

std::string Protein::getOrganism() const {
    return this->organism;
}

std::string Protein::getName() const {
    return this->name;
}

std::string Protein::getSequence() const {
    return this->sequence;
}
