#include "HTMLAdoptList.h"
#include "RepoException.h"
#include <fstream>

using namespace std;


HTMLAdoptList::HTMLAdoptList(const std::string &_filename, const std::string &_repofilename) :
    FileAdoptList(_filename, _repofilename) {}

void HTMLAdoptList::writeToFile() const {
    ofstream fout(filename);
    if(!fout.is_open())
        throw FileException("File not open for read");

    fout << "<!DOCTYPE html>\n<html>\n<head>\n\t<title>Adoption List</title>\n</head>\n";
    fout << "<body>\n<table border=\"1\">\n";

    fout << "\t<tr>\n";

    fout << "\t\t<td><b>Breed</b></td>\n";
    fout << "\t\t<td><b>Name</b></td>\n";
    fout << "\t\t<td><b>Age</b></td>\n";
    fout << "\t\t<td><b>Photograph</b></td>\n";

    fout << "\t</tr>\n";

    for (const auto &d: this->dogs)
        if(d.getFlag() == "true")
        {
            fout << "\t<tr>\n";

            fout << "\t\t<td>" << d.getBreed() << "</td>\n";
            fout << "\t\t<td>" << d.getName() << "</td>\n";
            fout << "\t\t<td>" << d.getAge() << "</td>\n";
            fout << "\t\t<td><a href=\"" << d.getPhotograph() << "\">Link</a></td>\n";

            fout << "\t</tr>\n";
        }

    fout << "</table>\n</body>\n</html>";

    fout.close();
}

void HTMLAdoptList::displayList() const {
    string command = "open " + filename;
    system(command.c_str());
}
