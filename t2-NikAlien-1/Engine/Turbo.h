#pragma once
#include "Engine.h"

class Turbo :
        public Engine{
public:
    Turbo(double price);

    double getPrice() override;
    std::string toString() override;
};
