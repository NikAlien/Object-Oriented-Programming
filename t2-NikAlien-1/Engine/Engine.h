#pragma once
#include "string"

class Engine {
protected:
    double basePrice;
public:
    Engine(double price);
    virtual double getPrice();
    virtual std::string toString() = 0;
    ~Engine() {};
};
