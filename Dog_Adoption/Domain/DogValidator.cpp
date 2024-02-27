//
// Created by Carp Nicoleta on 02.05.2023.
//

#include "DogValidator.h"

DogException::DogException(const std::vector<std::string> &e) {
    this->errors = e;
}

std::vector<std::string> DogException::getErrors() const {
    return this->errors;
}

void DogValidator::validate(const std::string &breed, const std::string &age) {
    std::vector<std::string> errors;
    int flag = 0;

    std::vector<const char*> breeds = {"husky", "chihuahua", "labrador", "bulldog", "shiba inu", "saluki",
                                       "corgi", "laika", "golden retriever", "pomeranian"};

    if(!std::any_of(breeds.begin(), breeds.end(), [&breed](const char* b){return breed == b;}))
        errors.push_back("\n!!! Breed not in data base !!!\n");

    for (char i : age)
        if (isdigit(i) == false) {
            errors.push_back("\n!!! Age should contain only digits !!!\n");
            flag = 1;
            break;
        }
    if(flag == 0) {
        int copy = std::stoi(age);
        if (copy < 0 or copy > 20)
            errors.push_back("\n!!! Age is invalid !!!\n");
    }

    if (errors.size() > 0)
        throw DogException(errors);
}
