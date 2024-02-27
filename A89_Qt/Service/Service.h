#pragma once
#include "FileAdoptList.h"
#include "Repo.h"
#include "DogValidator.h"

class Service
{
private:
    FileAdoptList* dog_list;
    DogValidator validator;
    int dogsAdopted;

public:
    //default constructor
    Service(FileAdoptList* list, const DogValidator& v);

    /* checks if dog with that name already exits, if not adds it to the repo
     * Input: breed - dog's breed
     *        name - dog's name
     *        age - dog's age
     *        photo - link to dog's photo
     * */
    void addDogToList(const std::string& breed, const std::string& name, const std::string& age, const std::string& photo);

    /* checks if dog with that name exits, if yes, removes from the repo
     * Input: name - dog's name
     * */
    void removeDogFromList(const std::string& name);

    /* checks if dog with that name exits, if yes, calls the update in repo function with the needed age
     * Input: name - dog's name
     *        age - dog's new age
     * Output: 1 - if updated with success
     *         0 - if dog doesn't exist
     * */
    void updateDogAge(const std::string& name, const std::string& age);

    /* checks if dog with that name exits, if yes, calls the update in repo function with the needed photo link
     * Input: name - dog's name
     *        photo - dog's new photo link
     * Output: 1 - if updated with success
     *         0 - if dog doesn't exist
     * */
    void updateDogPhoto(const std::string& name, const std::string& photo);

    // returns the array with all the dogs
    std::vector<Dog>* getDogList() const;

    // makes sure the name written by user has all lowercase, except the first letter
    static void makeNameValid(std::string& name);

    // makes sure the link written by user his an actual link that can be accessed
    // (even if the address have no webpage associated to it)
    static void makeLinkValid(std::string& link);

    /* depending on the filter(breed) given by the user and the age we create a dynamic array with pointers
     * to the needed dogs that are to be shown in the slideshow
     * Input: filter - a string that represents the wanted breeds, if it's empty than all breeds are considered
     *        age - if breed not empty than age must be smaller or equal to the given one
     * Output: a dynamic array with pointers to the needed dogs
     * */
    std::vector<Dog> createListUser(const std::string& filter, const std::string& age);

    //setter and getter for how many dogs are in the adoption list
    int getAdopted() const;
    void setAdopted(const std::string &name);

    void openAdoptList() const;
    void saveAdoptList() const;
};
