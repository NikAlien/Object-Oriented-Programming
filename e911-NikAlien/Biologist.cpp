//
// Created by Carp Nicoleta on 30.06.2023.
//

#include "Biologist.h"

std::string Biologist::toString() {
    std::string ss(this->name);
    ss.append(" - ");
    for(auto s: this->species)
    {
        ss.append(s);
        ss.append(" ");
    }
    ss.append("\n");
    return ss;
}
