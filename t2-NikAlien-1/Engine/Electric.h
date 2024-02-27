#pragma once
#include "Engine.h"

class Electric :
        public Engine{
private:
    int autonomy;
public:
    Electric(double price, int autonomy);

    double getPrice() override;
    std::string toString() override;
};

