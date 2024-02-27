#pragma once
#include "FileAdoptList.h"
#include <string>

class HTMLAdoptList :
        public FileAdoptList{
public:
    HTMLAdoptList(const std::string &_filename, const std::string &_repofilename);
    void writeToFile() const override;
    void displayList() const override;
};
