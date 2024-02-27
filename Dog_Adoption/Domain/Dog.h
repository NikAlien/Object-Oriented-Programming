#pragma once
#include <string>
#include <vector>
#include <iostream>

class Dog{
private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
    std::string clientList;

public:
    Dog(); // default constructor
    Dog(const std::string& breed, const std::string& name, int age, const std::string& photograph, const std::string& flag);

    // getters
    std::string getBreed() const;
    std::string getName() const;
    std::string getPhotograph() const;
    int getAge() const;
    std::string getFlag() const;

    // setters
    void setAge(int age);
    void setFlag(const std::string& flag);
    void setPhoto(const std::string& photo);

    friend std::istream& operator>>(std::istream& is, Dog& s);
    friend std::ostream& operator<<(std::ostream& os, const Dog& s);
};