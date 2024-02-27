#pragma once
#include "vector"
#include "string"
#include "exception"
#include "Dog.h"

class DogException
        : public std::exception
{
private:
    std::vector<std::string> errors;

public:
    DogException(const std::vector<std::string>& e);
    std::vector<std::string> getErrors() const;
};

class DogValidator
{
public:
    static void validate(const std::string& breed, const std::string& age);
};

