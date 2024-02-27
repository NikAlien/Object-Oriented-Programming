//
// Created by Carp Nicoleta on 30.06.2023.
//

#include "Bacterium.h"

std::string Bacterium::toString() {
    std::string ss(this->name);
    ss.append(",");
    ss.append(this->species);
    ss.append(",");
    ss.append(std::to_string(this->size));
    ss.append(",");
    for(auto s: this->diseases)
    {
        ss.append(s);
        ss.append(",");
    }
    ss.pop_back();
    ss.append("\n");
    return ss;
}

std::string Bacterium::getDiseases() {
    std::string ss;
    for(auto s: this->diseases)
    {
        ss.append(s);
        ss.append(" ");
    }
    ss.append("\n");
    return ss;
}

