#include <vector>
#include "Service.h"

Service::Service(Repository *repo) {
    this->dog_list = repo;
    this->dogsAdopted = 0;
}

int Service::addDogToList(const std::string& breed, const std::string& name, int age, const std::string& photo) {
    int verification = this->dog_list->searchDog(name);

    if(verification == -1) {
        Dog d(breed, name, age, photo, false);
        this->dog_list->addDog(d);
        return 1;
    }
    return 0;
}

int Service::removeDogFromList(const std::string &name) {
    int index = this->dog_list->searchDog(name);
    if(index == -1)
        return 0;
    this->dog_list->removeDog(index);
    return 1;
}

int Service::updateDogAge(const std::string &name, int age) {
    int index = this->dog_list->searchDog(name);
    if(index == -1)
        return 0;
    this->dog_list->updateDog(index, age, "");
    return 1;
}

int Service::updateDogPhoto(const std::string &name, const std::string &photo) {
    int index = this->dog_list->searchDog(name);
    if(index == -1)
        return 0;
    this->dog_list->updateDog(index, -1, photo);
    return 1;
}

std::vector<Dog> *Service::getDogList() const {
    return this->dog_list->getDogs();
}

bool Service::breedValid(const std::string &breed) {
    std::vector<const char*> breeds = {"husky", "chihuahua", "labrador", "bulldog", "shiba inu", "saluki",
                              "corgi", "laika", "golden retriever", "pomeranian"};
    if(std::any_of(breeds.begin(), breeds.end(), [&breed](const char* b){return breed == b;}))
            return true;
    return false;
}

bool Service::ageValid(const std::string& age) {

    for (char i : age)
        if (isdigit(i) == false)
            return false;

    int copy = std::stoi(age);
    if(copy < 0 or copy > 20)
        return false;
    return true;
}

void Service::makeNameValid(std::string &name) {
    for (auto & i : name) {
        if(i < 97)
            i += 32;
    }
    if(name[0] >90 )
        name[0] -= 32;
}

void Service::init() {
    this->addDogToList("husky", "Akira", 6, "https://www.megapet.ro/continut/upload//Husky-Siberian.jpg");
    this->addDogToList("chihuahua", "King", 3, "https://a-z-animals.com/media/2021/08/Chihuahua-puppy.jpg");
    this->addDogToList("husky", "Billy", 5, "https://www.insidedogsworld.com/wp-content/uploads/2016/12/husky10.jpg");
    this->addDogToList("labrador", "Merlin", 2, "https://worldofdogz.com/wp-content/uploads/2022/06/Labrador-Puppy-Training.jpg");
    this->addDogToList("bulldog", "Bobik", 14, "https://t3.ftcdn.net/jpg/00/52/00/62/360_F_52006242_7DzfYgOOB5M5IJ4IQ9DY1wnEJEMKjcKg.jpg");
    this->addDogToList("shiba inu", "Sharik", 1,"https://i.pinimg.com/originals/bf/14/58/bf14588294ae74853d8f44cb31c1c6f9.jpg");
    this->addDogToList("saluki", "Neil", 4, "https://upload.wikimedia.org/wikipedia/commons/3/31/Red_Smooth_Saluki.jpg");
    this->addDogToList("corgi", "Fairy", 9, "https://www.thefarmersdog.com/digest/wp-content/uploads/2021/12/corgi-top-1400x871.jpg");
    this->addDogToList("chihuahua", "Milo", 1, "https://d.newsweek.com/en/full/2202634/chihuahua.jpg");
    this->addDogToList("laika", "Wolf", 0, "https://www.akc.org/wp-content/uploads/2017/11/Yakutian-Laika-puppy.jpg");
}

void Service::makeLinkValid(std::string &link) {
    if(link.find("https://") == std::string::npos)
        link.insert(0, "https://");
}

std::vector<Dog *> Service::createListUser(std::string filter, int age) {
    std::vector<Dog*> filteredList;
    std::vector<Dog>* list = this->getDogList();
    if(filter.empty() && age == -1)
    {
        for(auto &d : *list)
        {
//            filteredList.insert(filteredList.end(), &d);
            filteredList.push_back(&d);
        }
    } else
    {
        for(auto &d: *list)
            if(d.getBreed() == filter && d.getAge() <= age)
                filteredList.push_back(&d);
    }
    return filteredList;
}

int Service::getAdopted() const {
    return this->dogsAdopted;
}

void Service::setAdopted(int counter) {
    this->dogsAdopted = counter;
}

