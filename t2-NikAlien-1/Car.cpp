#include "Car.h"
#include "Engine/Electric.h"
#include "Engine/Turbo.h"

Car::Car(std::string body, std::string engine, int autonomy) {
    this->bodyStyle = body;
    if(engine == "Electric")
        this->en = new Electric(3000, autonomy);
    else if(engine == "Turbo")
        this->en = new Turbo(3000);
}

double Car::computePrice() {
    double pr = 0;

    if(bodyStyle == "Sedan")
        pr += 8000;
    else if(bodyStyle == "Convertible")
        pr += 1000;
    pr += this->en->getPrice();
    return pr;
}

std::string Car::toStr() {
    std::string format;
    format.append(bodyStyle);
    format.append(en->toString());
    format.append(" Price: ");
    format.append(std::to_string(computePrice()));
    format.append("\n");
    return format;
}
