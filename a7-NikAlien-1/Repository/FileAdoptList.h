#pragma once
#include <string>
#include "Repo.h"

class FileAdoptList:
        public Repository
{
protected:
    std::string filename;

public:
    FileAdoptList(const std::string &_filename, const std::string &_repofilename);
    virtual void writeToFile() const = 0;
    virtual void displayList() const = 0;
    virtual ~FileAdoptList() {}
};
