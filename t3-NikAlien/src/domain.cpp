//
// Created by Carp Nicoleta on 25.05.2023.
//

#include "domain.h"
#include "sstream"

std::string Document::toString() {
    std::stringstream s;
    s << this->name << " - " << this->keywords;

    return s.str();
}
