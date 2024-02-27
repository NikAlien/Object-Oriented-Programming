#pragma once
#include <string>

class Dog
{
private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
    bool clienList;

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
};