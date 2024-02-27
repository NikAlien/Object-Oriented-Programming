#pragma once
#include "vector"
#include "string"
#include "Car.h"

class Service {
private:
    std::vector<Car> cars;

public:
    Service();

    void addCar(std::string body, std::string eng, int autonomy);
    void initRepo();
    std::vector<Car> getAll();
    std::vector<Car> getCarMaxPrice(double maxPrice);
    void writeToFile(std::string filename);

};

