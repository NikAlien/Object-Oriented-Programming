#pragma once
#include <vector>
#include "Dog.h"

class Repository
{
private:
    std::string filename;

    void readFile();
    void writeFile();

protected:
    std::vector<Dog> dogs;

public:
    // default constructor
    Repository(const std::string& filename);

    /* adds an element to the repo
     * Input: element of type TElem
     * */
    void addDog(const Dog d);

    /* removes a dog from the repo
     * Input: index - integer that signifies the position of the dog that's to be adopted
     * */
    void removeDog(int index);

    /* creates a new Dog entity with the update information
     * Input: index - position of element to be updated
     *        age - the new age
     *        photo - the new photo link
     * */
    void updateDog(int index, int age, const std::string& photo);

    void updateDogFlag(int index, const std::string& flag);

    /* searches for the position of the dog with the given name
     * Input: name - the dog's name, which is unique
     * Output: index of the dog's position in the array, -1 if doesn't exit
     * */
    int searchDog(const std::string& name);

    // returns the array with all the dogs
    std::vector<Dog>* getDogs();
};