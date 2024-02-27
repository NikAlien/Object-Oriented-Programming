#include "Service.h"

Service::Service() {
    this->initRepo();
}

void Service::initRepo() {
    this->addCar("Sedan", "Electric", 200);
    this->addCar("Sedan", "Turbo", 200);
    this->addCar("Convertible", "Electric", 200);
}

void Service::addCar(std::string body, std::string eng, int autonomy) {
    Car c(body, eng, autonomy);
    this->cars.push_back(c);
}

std::vector<Car> Service::getAll() {
    return cars;
}
