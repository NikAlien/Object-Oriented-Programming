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
    bool clientList;

public:
    Dog(); // default constructor
    Dog(const std::string& breed, const std::string& name, int age, const std::string& photograph, bool flag);

    // getters
    std::string getBreed() const;
    std::string getName() const;
    std::string getPhotograph() const;
    int getAge() const;
    bool getFlag() const;

    // setters
    void setAge(int age);
    void setFlag(bool flag);
    void setPhoto(const std::string& photo);

    friend std::istream& operator>>(std::istream& is, Dog& s);
    friend std::ostream& operator<<(std::ostream& os, const Dog& s);
};