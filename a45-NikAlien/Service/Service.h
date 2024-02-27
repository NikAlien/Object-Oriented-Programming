#pragma once
#include "Domain/Dog.h"
#include "Repository/DynamicArray.h"
#include "Repository/Repo.h"

class Service
{
private:
    Repository* dog_list;
    int dogsAdopted;

public:
    //default constructor
    Service(Repository* repo);

    //setter and getter for how many dogs are in the adoption list
    int getAdopted() const;
    void setAdopted(int counter);

    /* checks if dog with that name already exits, if not adds it to the repo
     * Input: breed - dog's breed
     *        name - dog's name
     *        age - dog's age
     *        photo - link to dog's photo
     * Output: 1 - if added with success
     *         0 - if dog with same name already in repo
     * */
    int addDogToList(const std::string& breed, const std::string& name, int age, const std::string& photo);

    /* checks if dog with that name exits, if yes, removes from the repo
     * Input: name - dog's name
     * Output: 1 - if removed with success
     *         0 - if dog doesn't exist
     * */
    int removeDogFromList(const std::string& name);

    /* checks if dog with that name exits, if yes, calls the update in repo function with the needed age
     * Input: name - dog's name
     *        age - dog's new age
     * Output: 1 - if updated with success
     *         0 - if dog doesn't exist
     * */
    int updateDogAge(const std::string& name, int age);

    /* checks if dog with that name exits, if yes, calls the update in repo function with the needed photo link
     * Input: name - dog's name
     *        photo - dog's new photo link
     * Output: 1 - if updated with success
     *         0 - if dog doesn't exist
     * */
    int updateDogPhoto(const std::string& name, const std::string& photo);

    // returns the array with all the dogs
    DynamicArray<Dog>* getDogList() const;

    /* checks if breed is valid, by looking in an array with possible breed names
     * Input: breed - the breed to be checked
     * Output: true - if breed is valid
     *         false - if breed is invalid
     * */
    bool breedValid(const std::string& breed);

    /* checks if age is valid, by checking if the given string has all characters as digit
     * if yes, checks that the number is not negative or bigger than 20 (possible age for dogs)
     * Input: age - the age string to be checked
     * Output: true - if age is valid
     *         false - if age is invalid
     * */
    bool ageValid(const std::string& age);

    // makes sure the name written by user has all lowercase, except the first letter
    static void makeNameValid(std::string& name);

    // makes sure the link written by user his an actual link that can be accessed
    // (even if the address have no webpage associated to it)
    static void makeLinkValid(std::string& link);

    // inserts 10 valid entries in the dog list
    void init();

    /* depending on the filter(breed) given by the user and the age we create a dynamic array with pointers
     * to the needed dogs that are to be shown in the slideshow
     * Input: filter - a string that represents the wanted breeds, if it's empty than all breeds are considered
     *        age - if breed not empty than age must be smaller or equal to the given one
     * Output: a dynamic array with pointers to the needed dogs
     * */
    DynamicArray<Dog*> createListUser(std::string filter, int age);
};
