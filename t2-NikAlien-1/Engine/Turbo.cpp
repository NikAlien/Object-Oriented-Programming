//
// Created by Carp Nicoleta on 11.05.2023.
//

#include "Turbo.h"

Turbo::Turbo(double price) : Engine(price) {

}

double Turbo::getPrice() {
    return this->basePrice + 100;
}

std::string Turbo::toString() {
    std::string format;
    format.append(" - Turbo engine - ");
    return format;
}
