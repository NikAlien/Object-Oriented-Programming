//
// Created by Carp Nicoleta on 11.05.2023.
//

#include "Electric.h"

Electric::Electric(double price, int autonomy): Engine(price) {
    this->autonomy = autonomy;
}

double Electric::getPrice() {
    return basePrice + autonomy * 0.01;
}

std::string Electric::toString() {
    std::string format;
    format.append(" - Electric engine - ");
    return format;
}

