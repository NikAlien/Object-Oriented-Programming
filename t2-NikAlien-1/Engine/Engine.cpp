//
// Created by Carp Nicoleta on 11.05.2023.
//

#include "Engine.h"

Engine::Engine(double price) {
    this->basePrice = price;
}

double Engine::getPrice() {
    return this->basePrice;
}
