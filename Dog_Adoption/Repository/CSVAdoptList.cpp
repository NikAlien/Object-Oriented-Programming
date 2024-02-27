#include "CSVAdoptList.h"
#include "RepoException.h"
#include <fstream>

using namespace std;

CSVAdoptList::CSVAdoptList(const std::string &_filename, const std::string &_repofilename) :
    FileAdoptList(_filename, _repofilename) {}

void CSVAdoptList::writeToFile() const {
    ofstream fout(filename);
    if(!fout.is_open())
        throw FileException("File not open for read");

    fout << "Breed,Name,Age,Photograph" << endl;

    for (const auto &d: this->dogs) {
        if(d.getFlag() == "true")
            fout << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getPhotograph() << "\n";
    }

    fout.close();
}

void CSVAdoptList::displayList() const {
    string command = "open " + filename;
    system(command.c_str());
}
