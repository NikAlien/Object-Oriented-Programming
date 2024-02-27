#pragma once
#include "string"
#include "Engine/Engine.h"

class Car {
private:
    std::string bodyStyle;
    Engine* en;
public:

    Car(std::string body, std::string engine, int autonomy);
    double computePrice();

    std::string toStr();
};

