#include "Repo.h"
#include "vector"
#include "fstream"
#include "RepoException.h"

Repository::Repository(const std::string& filename) {
    this->filename = filename;
    this->readFile();
}

void Repository::addDog(const Dog d) {
    dogs.push_back(d);
    this->writeFile();
}

std::vector<Dog> *Repository::getDogs() {
    return &(this->dogs);
}

void Repository::removeDog(int index) {
    this->dogs.erase(dogs.begin() + index);
    this->writeFile();
}

void Repository::updateDog(int index, int age, const std::string& photo) {
    Dog d = this->dogs.operator[](index);
    if(age < 0)
        d.setPhoto(photo);
    else
        d.setAge(age);
    this->dogs.at(index) = d;
    this->writeFile();
}

int Repository::searchDog(const std::string &name) {
    int index = 0;
    while(index < this->dogs.size())
    {
        if(name == this->dogs.operator[](index).getName())
            return index;
        index++;
    }
    return -1;
}

void Repository::readFile() {
    std::ifstream fin(this->filename);

    if(!fin.is_open())
        throw FileException("File not open for read");

    Dog s;
    while (fin >> s)
        this->dogs.push_back(s);

    fin.close();
}

void Repository::writeFile() {
    std::ofstream fout(this->filename);

    if(!fout.is_open())
        throw FileException("File not open for write");

    for (auto s : this->dogs)
        fout << s;

    fout.close();
}
